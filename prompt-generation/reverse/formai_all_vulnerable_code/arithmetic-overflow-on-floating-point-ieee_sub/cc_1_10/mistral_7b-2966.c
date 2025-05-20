//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

void die(const char *msg) {
    fprintf(stderr, "[%s] Error: %s\n", __func__, msg);
    exit(EXIT_FAILURE);
}

void check_div_by_zero(double value) {
    if (value == 0.0) {
        die("Division by zero");
    }
}

void calculate_line_intersection(double a1, double b1, double c1,
                                 double a2, double b2, double c2,
                                 Point *p1, Point *p2) {
    double determinant, x, y;

    // Check for parallel lines
    determinant = a1 * b2 - a2 * b1;
    if (determinant == 0.0) {
        die("Lines do not intersect, they are parallel");
    }

    // Calculate intersection point
    x = ((b1 * c2) - (b2 * c1)) / determinant;
    y = ((a1 * c2) - (a2 * c1)) / determinant;

    // Assign values to output points
    p1->x = x;
    p1->y = y;
    p2->x = x;
    p2->y = y;
}

void print_point(const Point *p) {
    printf("(%lf, %lf)\n", p->x, p->y);
}

int main() {
    Point p1, p2, q1, q2;
    double a1, b1, c1, a2, b2, c2;

    // Input line equations (ax + by + c = 0)
    printf("Enter coefficients a, b, and c for line 1: ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Enter coefficients a, b, and c for line 2: ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    // Check for potential division by zero errors
    check_div_by_zero(a1);
    check_div_by_zero(a2);

    // Calculate intersection point
    calculate_line_intersection(a1, b1, c1, a2, b2, c2, &p1, &p2);

    // Output intersection point(s)
    printf("Line intersection point(s):\n");
    print_point(&p1);
    print_point(&p2);

    return EXIT_SUCCESS;
}