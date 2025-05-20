//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int n;
    Point *points;
    int i, j;

    // Read number of points
    printf("Enter number of points: ");
    scanf("%d", &n);

    // Allocate memory for points
    points = (Point *)malloc(n * sizeof(Point));

    // Read points
    printf("Enter coordinates of points:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Calculate convex hull
    Point *hull = (Point *)malloc(n * sizeof(Point));
    int k = 0;
    for (i = 0; i < n; i++) {
        int j = 0;
        while (j < k && ((hull[j].y - points[i].y) * (hull[(j + 1) % k].x - points[i].x) <= 0)) {
            j++;
        }
        hull[k] = points[i];
        k++;
    }

    // Print convex hull
    printf("Convex hull:\n");
    for (i = 0; i < k; i++) {
        printf("%d %d\n", hull[i].x, hull[i].y);
    }

    // Free memory
    free(points);
    free(hull);

    return 0;
}