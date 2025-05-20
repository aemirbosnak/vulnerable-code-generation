//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y, z;
} Point;

void print_point(Point p) {
    printf("(%d, %d, %d)\n", p.x, p.y, p.z);
}

typedef struct {
    Point *vertices;
    int num_vertices;
} Shape;

void print_shape(Shape s) {
    for (int i = 0; i < s.num_vertices; i++) {
        print_point(s.vertices[i]);
    }
}

typedef struct {
    Shape *shapes;
    int num_shapes;
} Scene;

void print_scene(Scene s) {
    for (int i = 0; i < s.num_shapes; i++) {
        print_shape(s.shapes[i]);
    }
}

int main() {
    srand(time(NULL));

    Point p1 = {rand() % 100, rand() % 100, rand() % 100};
    Point p2 = {rand() % 100, rand() % 100, rand() % 100};
    Point p3 = {rand() % 100, rand() % 100, rand() % 100};
    Point p4 = {rand() % 100, rand() % 100, rand() % 100};

    Shape cube = {
       .vertices = malloc(sizeof(Point) * 8),
       .num_vertices = 8
    };

    cube.vertices[0] = p1;
    cube.vertices[1] = p2;
    cube.vertices[2] = p3;
    cube.vertices[3] = p4;

    for (int i = 4; i < 8; i++) {
        Point p = {
            cube.vertices[i - 4].x + (cube.vertices[(i - 4) % 4].x - cube.vertices[(i - 5) % 4].x) / 2,
            cube.vertices[i - 4].y + (cube.vertices[(i - 4) % 4].y - cube.vertices[(i - 5) % 4].y) / 2,
            cube.vertices[i - 4].z + (cube.vertices[(i - 4) % 4].z - cube.vertices[(i - 5) % 4].z) / 2
        };
        cube.vertices[i] = p;
    }

    Scene scene = {
       .shapes = malloc(sizeof(Shape) * 1),
       .num_shapes = 1
    };

    scene.shapes[0] = cube;

    print_scene(scene);

    free(cube.vertices);
    free(scene.shapes[0].vertices);
    free(scene.shapes);

    return 0;
}