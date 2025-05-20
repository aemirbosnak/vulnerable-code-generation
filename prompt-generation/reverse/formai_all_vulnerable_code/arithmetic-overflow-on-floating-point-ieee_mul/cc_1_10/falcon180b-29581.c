//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Point p;
    double a;
    double b;
    double c;
} Circle;

int is_on_line(Line l, Point p) {
    double k = (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
    double b = l.p1.y - k * l.p1.x;
    double t = (p.y - k * p.x - b) / sqrt(k * k + 1);
    if (t >= 0 && t <= 1) {
        return 1;
    }
    return 0;
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double area(Circle c) {
    return 3.14159265358979323846 * c.a * c.b;
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {10, 0};
    Point p3 = {10, 10};
    Point p4 = {0, 10};
    Line l = {p1, p2};
    Circle c = {p2, sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)), sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2))};
    Point p = {5, 5};
    if (is_on_line(l, p)) {
        printf("Point is on line\n");
    } else {
        printf("Point is not on line\n");
    }
    printf("Distance between p1 and p2 is %.2f\n", distance(p1, p2));
    printf("Area of circle is %.2f\n", area(c));
    return 0;
}