﻿//
// Copyright(c) 2016-2017 benikabocha.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#ifndef SABA_GL_MODEL_MMD_GLMMDMODELDRAWER_H_
#define SABA_GL_MODEL_MMD_GLMMDMODELDRAWER_H_

#include "GLMMDModel.h"
#include <Saba/Viewer/ModelDrawer.h>

#include <vector>

#include <glm/mat4x4.hpp>

namespace saba
{
	class GLMMDModelDrawContext;

	class GLMMDModelDrawer : public ModelDrawer
	{
	public:
		GLMMDModelDrawer(GLMMDModelDrawContext* ctxt, std::shared_ptr<GLMMDModel> mmdModel);
		~GLMMDModelDrawer() override;

		GLMMDModelDrawer(const GLMMDModelDrawer&) = delete;
		GLMMDModelDrawer& operator =(const GLMMDModelDrawer&) = delete;

		bool Create();
		void Destroy();

		ModelDrawerType GetType() const override { return ModelDrawerType::MMDModelDrawer; }

		void Play() override;
		void Stop() override;

		void ResetAnimation(ViewerContext* ctxt) override;
		void Update(ViewerContext* ctxt) override;
		void DrawUI(ViewerContext* ctxt) override;
		void Draw(ViewerContext* ctxt) override;

		GLMMDModel* GetModel() { return m_mmdModel.get(); }

	private:
		struct MaterialShader
		{
			int					m_mmdMaterialIndex;
			int					m_mmdShaderIndex;
			GLVertexArrayObject	m_mmdVao;
			int					m_mmdEdgeShaderIndex;
			GLVertexArrayObject	m_mmdEdgeVao;
		};

	private:
		GLMMDModelDrawContext*		m_drawContext;
		std::shared_ptr<GLMMDModel>	m_mmdModel;

		std::vector<MaterialShader>	m_materialShaders;

		glm::mat4	m_world;


		// IMGui
		bool		m_clipElapsed;
		bool		m_viewLocal;
		MMDNode*	m_selectedNode;
	};
}

#endif // !SABA_GL_MODEL_MMD_GLMMDMODELDRAWER_H_
