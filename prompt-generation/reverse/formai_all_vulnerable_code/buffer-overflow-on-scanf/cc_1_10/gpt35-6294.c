//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
/*
* This program calculates various geometric parameters for a given polygon consisting of n points in a two-dimensional plane.
* The algorithm uses the shoelace formula, also known as Gauss's area formula, to calculate the area of the polygon.
* Then, it computes the perimeter, centroid, and moments of inertia of the polygon, and outputs the results to the console.

* Author: Statistical Genius (sgenius@stats.com)
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    int num_vertices;
    Point vertices[100];
} Polygon;

double shoelace_formula(Polygon poly) {
    double a = 0.0;
    for (int i = 0; i < poly.num_vertices; ++i) {
        int j = (i + 1) % poly.num_vertices;
        a += poly.vertices[i].x * poly.vertices[j].y;
        a -= poly.vertices[j].x * poly.vertices[i].y;
    }
    return 0.5 * fabs(a);
}

double perimeter(Polygon poly) {
    double p = 0.0;
    for (int i = 0; i < poly.num_vertices; ++i) {
        int j = (i + 1) % poly.num_vertices;
        double dx = poly.vertices[j].x - poly.vertices[i].x;
        double dy = poly.vertices[j].y - poly.vertices[i].y;
        p += sqrt(dx*dx + dy*dy);
    }
    return p;
}

Point centroid(Polygon poly) {
    Point c = {0.0, 0.0};
    double a = shoelace_formula(poly);
    for (int i = 0; i < poly.num_vertices; ++i) {
        int j = (i + 1) % poly.num_vertices;
        double dx = poly.vertices[i].x + poly.vertices[j].x;
        double dy = poly.vertices[i].y + poly.vertices[j].y;
        c.x += dx * (poly.vertices[i].x * poly.vertices[j].y - poly.vertices[j].x * poly.vertices[i].y);
        c.y += dy * (poly.vertices[i].x * poly.vertices[j].y - poly.vertices[j].x * poly.vertices[i].y);
    }
    c.x /= 6*a;
    c.y /= 6*a;
    return c;
}

double moment_of_inertia(Polygon poly) {
    double I = 0.0;
    Point c = centroid(poly);
    for (int i = 0; i < poly.num_vertices; ++i) {
        int j = (i + 1) % poly.num_vertices;
        double ai = poly.vertices[i].x * poly.vertices[j].y - poly.vertices[j].x * poly.vertices[i].y;
        double ri = sqrt((poly.vertices[i].x - c.x)*(poly.vertices[i].x - c.x) + (poly.vertices[i].y - c.y)*(poly.vertices[i].y - c.y));
        double rj = sqrt((poly.vertices[j].x - c.x)*(poly.vertices[j].x - c.x) + (poly.vertices[j].y - c.y)*(poly.vertices[j].y - c.y));
        double theta = atan2(poly.vertices[j].y - poly.vertices[i].y, poly.vertices[j].x - poly.vertices[i].x);
        I += (ri*ri + ri*rj + rj*rj) * ai * theta / 3.0;
    }
    return I;
}

int main() {
    Polygon poly;
    printf("Enter number of vertices (maximum 100): ");
    scanf("%d", &poly.num_vertices);
    for (int i = 0; i < poly.num_vertices; ++i) {
        printf("Enter x and y coordinates of vertex %d: ", i+1);
        scanf("%lf %lf", &poly.vertices[i].x, &poly.vertices[i].y);
    }
    double a = shoelace_formula(poly);
    double p = perimeter(poly);
    Point c = centroid(poly);
    double I = moment_of_inertia(poly);
    printf("Area: %lf\nPerimeter: %lf\nCentroid: (%lf, %lf)\nMoment of Inertia: %lf\n", a, p, c.x, c.y, I);
    return 0;
}