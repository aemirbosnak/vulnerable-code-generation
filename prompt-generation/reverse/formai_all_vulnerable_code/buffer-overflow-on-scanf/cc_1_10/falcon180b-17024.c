//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

int is_point_in_circle(Circle circle, Point point) {
    double distance = sqrt(pow(point.x - circle.center.x, 2) + pow(point.y - circle.center.y, 2));

    if (distance <= circle.radius) {
        return 1;
    }

    return 0;
}

int main() {
    int num_circles;
    int i;
    Point point;
    Circle circles[100];

    printf("Enter the number of circles: ");
    scanf("%d", &num_circles);

    for (i = 0; i < num_circles; i++) {
        printf("Enter the center of circle %d (x y): ", i + 1);
        scanf("%lf %lf", &circles[i].center.x, &circles[i].center.y);

        printf("Enter the radius of circle %d: ", i + 1);
        scanf("%lf", &circles[i].radius);
    }

    printf("Enter a point to check: ");
    scanf("%lf %lf", &point.x, &point.y);

    for (i = 0; i < num_circles; i++) {
        if (is_point_in_circle(circles[i], point)) {
            printf("Point is in circle %d\n", i + 1);
        }
    }

    return 0;
}