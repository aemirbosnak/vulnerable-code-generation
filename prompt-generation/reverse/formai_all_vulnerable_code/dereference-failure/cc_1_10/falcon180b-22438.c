//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 1000

typedef struct {
    double x, y;
} Point;

Point points[MAX_POINTS];
int num_points;

void add_point(double x, double y) {
    if (num_points >= MAX_POINTS) {
        printf("Error: Too many points!\n");
        return;
    }
    points[num_points].x = x;
    points[num_points].y = y;
    num_points++;
}

void print_points() {
    int i;
    for (i = 0; i < num_points; i++) {
        printf("(%f, %f)\n", points[i].x, points[i].y);
    }
}

void convex_hull() {
    int i, j, k, n;
    Point *hull = malloc(sizeof(Point) * num_points);
    int hull_size = 0;

    // Initialize the lower hull
    for (i = 0; i < num_points; i++) {
        if (points[i].x < points[0].x) {
            hull[hull_size++] = points[i];
        }
    }

    // Add points to the hull
    for (i = 1; i < num_points; i++) {
        Point p = points[i];
        int j = hull_size - 2;
        while (j >= 0 && (hull[j].x - hull[j + 1].x) * (p.y - hull[j + 1].y) > (p.x - hull[j + 1].x) * (hull[j].y - hull[j + 1].y)) {
            j--;
        }
        hull[j + 1] = p;
        hull_size++;
    }

    // Print the convex hull
    printf("Convex hull:\n");
    for (i = 0; i < hull_size; i++) {
        printf("(%f, %f)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    int i;
    for (i = 0; i < num_points; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    convex_hull();
    return 0;
}