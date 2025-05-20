//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <malloc.h>
#include <GL/glut.h>

// Global Variables
int num_frames = 0;
int num_items = 0;
int height = 0;
int x_offset = 0;
int y_offset = 0;
float frame_rate = 0.05;

// Prototypes
void init();
void display();
void specialKeys(int key, int x, int y);
void motion(int x, int y);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void timer(int value);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Stack Animation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutMotionFunc(motion);
    glutTimerFunc(1000 / frame_rate, timer, 0);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}

void init()
{
    num_items = 10;
    height = 100;
    x_offset = (glutGet(GLUT_WINDOW_WIDTH) - 100) / 2;
    y_offset = (glutGet(GLUT_WINDOW_HEIGHT) - 100) / 2;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(x_offset, y_offset, 0);
    glRotatef(num_frames * 360 / num_items, 0, 0, 1);
    glScalef(1.5, 1.5, 1.5);

    glPushMatrix();
    glTranslatef(0, 0, -height);
    glScalef(1, 1, 1);
    glBegin(GL_QUADS);
    // draw each item as a quad with color (1, 1, 1)
    glVertex3f(-10, -10, -10);
    glVertex3f(-10, 10, -10);
    glVertex3f(10, 10, -10);
    glVertex3f(10, -10, -10);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glFlush();
    num_frames++;
    if (num_frames >= num_items) {
        num_frames = 0;
    }
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP) {
        glutPostRedisplay();
    }
}

void motion(int x, int y)
{
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    if (h > 0) {
        height = h - 100;
    }
    if (w > 0) {
        x_offset = (w - 100) / 2;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) {
        glutDestroyWindow("Stack Animation");
        return;
    }
    if (key == 'r') {
        init();
        glutPostRedisplay();
    }
}

void timer(int value)
{
    glutTimerFunc(1000 / frame_rate, timer, 0);
}