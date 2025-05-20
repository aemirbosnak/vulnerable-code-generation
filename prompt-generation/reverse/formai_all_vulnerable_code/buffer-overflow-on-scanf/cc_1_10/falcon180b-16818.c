//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

struct Point {
    double x;
    double y;
};

struct Edge {
    struct Point start;
    struct Point end;
};

struct Triangle {
    struct Point a;
    struct Point b;
    struct Point c;
};

struct Triangle *generate_triangle(struct Point *points, int num_points) {
    struct Triangle *triangle = malloc(sizeof(struct Triangle));
    triangle->a = points[0];
    triangle->b = points[1];
    triangle->c = points[2];
    return triangle;
}

double triangle_area(struct Triangle *triangle) {
    double area = 0;
    double a = triangle->a.x * triangle->b.y + triangle->b.x * triangle->c.y + triangle->c.x * triangle->a.y;
    double b = triangle->a.x * triangle->c.y + triangle->c.x * triangle->b.y + triangle->b.x * triangle->a.y;
    double c = triangle->b.x * triangle->a.y + triangle->a.x * triangle->c.y + triangle->c.x * triangle->b.y;
    area = sqrt(a + b + c) / 2;
    return area;
}

int main() {
    struct Point points[MAX_SIZE];
    int num_points = 0;
    double x, y;

    printf("Enter the coordinates of the points (x y):\n");
    while (num_points < 3) {
        scanf("%lf %lf", &x, &y);
        points[num_points] = (struct Point){x, y};
        num_points++;
    }

    struct Triangle *triangle = generate_triangle(points, num_points);
    double area = triangle_area(triangle);

    printf("The area of the triangle is %.2lf\n", area);

    return 0;
}