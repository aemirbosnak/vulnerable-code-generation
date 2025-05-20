//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point a;
    point b;
} line;

double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n, i, j;
    double min_dist;
    point points[100];
    line lines[100];

    // Read the input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &lines[i].a.x, &lines[i].a.y, &lines[i].b.x, &lines[i].b.y);
    }

    // Find the minimum distance between any two points
    min_dist = dist(points[0], points[1]);
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (dist(points[i], points[j]) < min_dist) {
                min_dist = dist(points[i], points[j]);
            }
        }
    }

    // Find the minimum distance between any point and any line
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            double d = ((lines[j].b.y - lines[j].a.y) * points[i].x - (lines[j].b.x - lines[j].a.x) * points[i].y + (lines[j].b.x * lines[j].a.y - lines[j].b.y * lines[j].a.x)) / sqrt((lines[j].b.y - lines[j].a.y) * (lines[j].b.y - lines[j].a.y) + (lines[j].b.x - lines[j].a.x) * (lines[j].b.x - lines[j].a.x));
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }

    // Print the minimum distance
    printf("%.6lf\n", min_dist);

    return 0;
}