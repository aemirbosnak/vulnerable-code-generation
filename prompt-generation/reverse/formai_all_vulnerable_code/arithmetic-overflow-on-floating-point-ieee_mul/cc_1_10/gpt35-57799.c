//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// Define a structure to hold a 2D point
struct Point {
    double x, y;
};

// This function returns the distance between two points
double distance(struct Point p1, struct Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// This function returns the circumcircle radius of a given triangle
double circumcircle_radius(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    double numerator = a * b * c;
    double denominator = 4 * sqrt(s * (s-a) * (s-b) * (s-c));
    return numerator / denominator;
}

// This function returns the area of a given triangle
double area(struct Point p1, struct Point p2, struct Point p3) {
    return fabs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y))/2);
}

// This function returns 1 if a given point is inside a given triangle, otherwise 0
int is_inside(struct Point p, struct Point p1, struct Point p2, struct Point p3) {
    double A = area(p1, p2, p3);
    double A1 = area(p, p2, p3);
    double A2 = area(p1, p, p3);
    double A3 = area(p1, p2, p);
    return (A == A1 + A2 + A3);
}

int main() {
    struct Point p = {3, 4};
    struct Point p1 = {0, 0};
    struct Point p2 = {0, 5};
    struct Point p3 = {5, 0};
    double r = circumcircle_radius(p1, p2, p3);
    double area_t = area(p1, p2, p3);

    printf("The circumcircle radius of the triangle is %lf\n", r);
    printf("The area of the triangle is %lf\n", area_t);

    if (is_inside(p, p1, p2, p3)) {
        printf("The point (%lf, %lf) is inside the triangle\n", p.x, p.y);
    } else {
        printf("The point (%lf, %lf) is not inside the triangle\n", p.x, p.y);
    }

    return 0;
}