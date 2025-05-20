//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
#define PI 3.14159265358979323846

struct point {
    double x;
    double y;
};

struct line {
    double a;
    double b;
    double c;
};

struct line get_line(struct point p1, struct point p2) {
    struct line l;
    l.a = p2.y - p1.y;
    l.b = p1.x - p2.x;
    l.c = p1.x * p2.y - p1.y * p2.x;
    return l;
}

double get_distance(struct point p1, struct point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double get_slope(struct line l) {
    return -l.a / l.b;
}

double get_y_intercept(struct line l, double x) {
    return l.a * x + l.c;
}

int main() {
    int n, i, j;
    struct point points[MAX];
    struct line line;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coordinates of point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            line = get_line(points[i], points[j]);
            double slope1 = get_slope(line);
            double slope2 = (points[j].y - points[i].y) / (points[j].x - points[i].x);

            if (slope1!= slope2) {
                printf("Point %d and point %d are not on the same line.\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}