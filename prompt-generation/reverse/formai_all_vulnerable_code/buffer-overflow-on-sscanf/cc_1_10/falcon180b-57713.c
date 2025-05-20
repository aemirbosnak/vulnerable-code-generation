//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE 1000
#define MAX_WORD 100
#define PI 3.14159265358979323846

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    double a, b, c, d;
} Matrix;

void identity(Matrix *m) {
    m->a = 1.0;
    m->b = 0.0;
    m->c = 0.0;
    m->d = 1.0;
}

void multiply(Matrix *a, Matrix *b, Matrix *c) {
    c->a = a->a * b->a + a->b * b->c;
    c->b = a->a * b->b + a->b * b->d;
    c->c = a->c * b->a + a->d * b->c;
    c->d = a->c * b->b + a->d * b->d;
}

void rotate(Matrix *m, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    Matrix r;
    identity(&r);
    r.a = cosine;
    r.b = -sine;
    r.c = sine;
    r.d = cosine;
    multiply(m, &r, m);
}

void transform(Matrix *m, Vector *v) {
    Vector r;
    r.x = m->a * v->x + m->b * v->y + m->c * v->z + m->d;
    r.y = m->a * v->y + m->b * v->x - m->c * v->z + m->d;
    r.z = m->a * v->z - m->b * v->y + m->c * v->x + m->d;
    *v = r;
}

int main() {
    char line[MAX_LINE];
    char word[MAX_WORD];
    FILE *fp;
    double temperature;
    Vector eye;
    Vector lookat;
    Vector up;
    Matrix projection;
    Matrix view;
    Matrix model;

    identity(&projection);
    identity(&view);
    identity(&model);

    fp = fopen("scene.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open scene file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (sscanf(line, "temperature %lf", &temperature) == 1) {
            // Rotate the camera around the scene
            eye.x = 0.0;
            eye.y = 0.0;
            eye.z = 10.0 * sin(temperature * PI / 180.0);
            lookat.x = 0.0;
            lookat.y = 0.0;
            lookat.z = 0.0;
            up.x = 0.0;
            up.y = 1.0;
            up.z = 0.0;
            transform(&view, &eye);
            transform(&view, &lookat);
            transform(&view, &up);
            transform(&projection, &eye);
            transform(&projection, &lookat);
            transform(&projection, &up);
            transform(&model, &eye);
            transform(&model, &lookat);
            transform(&model, &up);
        }
    }

    fclose(fp);

    return 0;
}