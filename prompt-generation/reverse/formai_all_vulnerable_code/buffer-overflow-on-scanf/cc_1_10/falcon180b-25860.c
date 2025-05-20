//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTS 100

typedef struct {
    int x, y;
} Vertex;

typedef struct {
    Vertex *verts;
    int num_verts;
} Polygon;

void read_polygon(Polygon *poly) {
    printf("Enter the number of vertices: ");
    scanf("%d", &poly->num_verts);
    poly->verts = (Vertex *) malloc(poly->num_verts * sizeof(Vertex));
    for (int i = 0; i < poly->num_verts; i++) {
        printf("Enter vertex %d (x y): ", i+1);
        scanf("%d %d", &poly->verts[i].x, &poly->verts[i].y);
    }
}

void print_polygon(Polygon *poly) {
    for (int i = 0; i < poly->num_verts; i++) {
        printf("(%d %d) ", poly->verts[i].x, poly->verts[i].y);
    }
    printf("\n");
}

void rotate_polygon(Polygon *poly, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    Vertex *center = (Vertex *) malloc(sizeof(Vertex));
    center->x = 0;
    center->y = 0;
    for (int i = 0; i < poly->num_verts; i++) {
        Vertex *vertex = &poly->verts[i];
        double x_diff = vertex->x - center->x;
        double y_diff = vertex->y - center->y;
        double rotated_x = x_diff * cos_angle - y_diff * sin_angle;
        double rotated_y = x_diff * sin_angle + y_diff * cos_angle;
        vertex->x = rotated_x + center->x;
        vertex->y = rotated_y + center->y;
    }
    free(center);
}

int main() {
    Polygon poly;
    read_polygon(&poly);
    printf("Original polygon:\n");
    print_polygon(&poly);
    rotate_polygon(&poly, M_PI/4);
    printf("Rotated polygon:\n");
    print_polygon(&poly);
    return 0;
}