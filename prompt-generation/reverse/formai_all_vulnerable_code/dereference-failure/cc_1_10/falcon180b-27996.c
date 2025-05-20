//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTS 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *verts;
    int num_verts;
} Polygon;

void add_point(Polygon *poly, int x, int y)
{
    if (poly->num_verts >= MAX_VERTS) {
        printf("Error: Too many vertices in polygon.\n");
        exit(1);
    }
    poly->verts[poly->num_verts++] = (Point){x, y};
}

void print_polygon(Polygon *poly)
{
    printf("Polygon with %d vertices:\n", poly->num_verts);
    for (int i = 0; i < poly->num_verts; i++) {
        printf("(%d, %d)\n", poly->verts[i].x, poly->verts[i].y);
    }
}

int is_convex(Polygon *poly)
{
    for (int i = 0; i < poly->num_verts - 2; i++) {
        int j = i + 1;
        int k = i + 2;
        if (cross_product(poly->verts[j], poly->verts[i], poly->verts[k])!= 0) {
            return 0;
        }
    }
    return 1;
}

int cross_product(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main()
{
    Polygon poly;
    poly.num_verts = 0;

    add_point(&poly, 0, 0);
    add_point(&poly, 1, 0);
    add_point(&poly, 1, 1);
    add_point(&poly, 0, 1);

    print_polygon(&poly);

    if (is_convex(&poly)) {
        printf("Polygon is convex.\n");
    } else {
        printf("Polygon is not convex.\n");
    }

    return 0;
}