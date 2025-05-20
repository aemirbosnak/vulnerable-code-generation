//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

Circle createCircle(double x, double y, double r) {
    Circle c;
    c.center.x = x;
    c.center.y = y;
    c.radius = r;
    return c;
}

double getDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double getCirclePerimeter(Circle c) {
    return 2 * PI * c.radius;
}

double getCircleArea(Circle c) {
    return PI * c.radius * c.radius;
}

int isPointInCircle(Point p, Circle c) {
    double d = getDistance(p, c.center);
    return d <= c.radius;
}

int main() {
    int n;
    scanf("%d", &n);
    Point points[n];
    Circle circle;

    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double minDistance = 1e9;
    for(int i = 0; i < n; i++) {
        double d = getDistance(points[i], points[(i+1)%n]);
        if(d < minDistance) {
            minDistance = d;
        }
    }

    circle.center.x = 0;
    circle.center.y = 0;
    circle.radius = minDistance / 2;

    for(int i = 0; i < n; i++) {
        if(!isPointInCircle(points[i], circle)) {
            printf("Invalid input\n");
            return 0;
        }
    }

    printf("Perimeter: %.2lf\n", getCirclePerimeter(circle));
    printf("Area: %.2lf\n", getCircleArea(circle));

    return 0;
}