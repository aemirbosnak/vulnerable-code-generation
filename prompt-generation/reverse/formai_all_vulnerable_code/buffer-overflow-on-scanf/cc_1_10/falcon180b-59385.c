//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 100

typedef struct {
    int x, y;
} Point;

int main() {
    int n, i, j;
    Point points[MAX_POINTS];

    // Read the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Read the coordinates of the points
    for (i = 0; i < n; i++) {
        printf("Enter the coordinates of point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Calculate the convex hull of the points
    int hull_size = 0;
    Point hull[MAX_POINTS];
    hull[hull_size++] = points[0];
    for (i = 1; i < n; i++) {
        int j = hull_size - 1;
        while (j >= 0 && cross_product(hull[j], points[i], hull[j - 1]) <= 0) {
            j--;
        }
        hull[j + 1] = points[i];
        hull_size++;
    }

    // Print the convex hull
    printf("Convex hull:\n");
    for (i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }

    return 0;
}

// Calculate the cross product of two vectors
int cross_product(Point p1, Point p2, Point p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}