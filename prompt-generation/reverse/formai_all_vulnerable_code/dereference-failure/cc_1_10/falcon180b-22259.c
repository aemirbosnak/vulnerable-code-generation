//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    Vector *vertices;
    int num_vertices;
} Mesh;

Mesh *create_sphere_mesh(double radius, int num_subdivisions) {
    Mesh *mesh = malloc(sizeof(Mesh));
    mesh->num_vertices = (num_subdivisions + 1) * (num_subdivisions + 1);
    mesh->vertices = malloc(sizeof(Vector) * mesh->num_vertices);

    double phi, theta;
    for (int i = 0; i <= num_subdivisions; i++) {
        phi = M_PI * i / num_subdivisions;
        for (int j = 0; j <= num_subdivisions; j++) {
            theta = 2 * M_PI * j / num_subdivisions;
            Vector vertex;
            vertex.x = radius * sin(phi) * cos(theta);
            vertex.y = radius * sin(phi) * sin(theta);
            vertex.z = radius * cos(phi);
            mesh->vertices[i * (num_subdivisions + 1) + j] = vertex;
        }
    }

    return mesh;
}

void destroy_mesh(Mesh *mesh) {
    free(mesh->vertices);
    free(mesh);
}

void print_mesh(Mesh *mesh) {
    for (int i = 0; i < mesh->num_vertices; i++) {
        Vector vertex = mesh->vertices[i];
        printf("(%f, %f, %f)\n", vertex.x, vertex.y, vertex.z);
    }
}

int main() {
    srand(time(NULL));

    Mesh *mesh = create_sphere_mesh(1.0, 10);
    print_mesh(mesh);

    destroy_mesh(mesh);

    return 0;
}