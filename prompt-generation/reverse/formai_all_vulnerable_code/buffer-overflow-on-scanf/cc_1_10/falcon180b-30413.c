//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point;

void read_points(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter point %d (x y): ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void print_points(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void convex_hull(Point points[], int n) {
    int hull_size = 0;
    Point hull[MAX_POINTS];

    // Initialize the hull with the first point
    hull[hull_size++] = points[0];

    // Add the remaining points to the hull
    for (int i = 1; i < n; i++) {
        int j = hull_size - 1;
        while (j >= 0 && points[i].y <= hull[j].y) {
            j--;
        }
        hull[++j] = points[i];
    }

    // Print the hull points
    printf("Convex hull:\n");
    for (int i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[MAX_POINTS];
    read_points(points, n);

    convex_hull(points, n);

    return 0;
}