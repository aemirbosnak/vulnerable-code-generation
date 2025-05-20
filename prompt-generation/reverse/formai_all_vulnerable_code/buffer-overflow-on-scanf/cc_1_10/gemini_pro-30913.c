//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9
#define MAX_POINTS 100000

typedef struct {
    double x, y;
} point;

typedef struct {
    point p1, p2;
} line;

typedef struct {
    point p1, p2, p3;
} triangle;

int ccw(point a, point b, point c) {
    double dx1 = b.x - a.x;
    double dy1 = b.y - a.y;
    double dx2 = c.x - a.x;
    double dy2 = c.y - a.y;
    double cross = dx1 * dy2 - dx2 * dy1;
    if (cross > EPS) {
        return 1;
    } else if (cross < -EPS) {
        return -1;
    } else {
        return 0;
    }
}

double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double area(triangle t) {
    double a = dist(t.p1, t.p2);
    double b = dist(t.p2, t.p3);
    double c = dist(t.p3, t.p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int n;
    scanf("%d", &n);
    point points[MAX_POINTS];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    int hull_size = 0;
    int hull[MAX_POINTS];
    for (int i = 0; i < n; i++) {
        while (hull_size >= 2 && ccw(points[hull[hull_size - 2]], points[hull[hull_size - 1]], points[i]) <= 0) {
            hull_size--;
        }
        hull[hull_size++] = i;
    }
    for (int i = n - 2; i >= 0; i--) {
        while (hull_size >= 2 && ccw(points[hull[hull_size - 2]], points[hull[hull_size - 1]], points[i]) <= 0) {
            hull_size--;
        }
        hull[hull_size++] = i;
    }
    double max_area = 0;
    triangle best_triangle;
    for (int i = 0; i < hull_size; i++) {
        for (int j = i + 1; j < hull_size; j++) {
            for (int k = j + 1; k < hull_size; k++) {
                triangle t = {points[hull[i]], points[hull[j]], points[hull[k]]};
                double a = area(t);
                if (a > max_area) {
                    max_area = a;
                    best_triangle = t;
                }
            }
        }
    }
    printf("%.6lf\n", max_area);
    return 0;
}