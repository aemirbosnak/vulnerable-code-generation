//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

// Function to find the orientation of the triplet (p, q, r)
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Function to compare two points according to polar angle
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    // Check for the lowest y-coordinate
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return (p1->x < p2->x) ? -1 : 1;
}

// Function to compute the convex hull
void convexHull(Point *points, int n) {
    // Find the point with the lowest y-coordinate
    Point p0 = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].y < p0.y || (points[i].y == p0.y && points[i].x < p0.x)) {
            p0 = points[i];
        }
    }

    // Sort points by polar angle with respect to p0
    qsort(points, n, sizeof(Point), compare);

    // Create an array to store the Convex Hull points
    Point *hull = malloc(n * sizeof(Point));
    if (hull == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    int hullIndex = 0;
    hull[hullIndex++] = points[0];
    
    for (int i = 1; i < n; i++) {
        while (hullIndex >= 2 && orientation(hull[hullIndex - 2], hull[hullIndex - 1], points[i]) != 2) {
            hullIndex--;
        }
        hull[hullIndex++] = points[i];
    }

    // Output the convex hull vertices
    printf("Convex hull points:\n");
    for (int i = 0; i < hullIndex; i++) {
        printf("(%lf, %lf)\n", hull[i].x, hull[i].y);
    }

    // Free the allocated memory
    free(hull);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    Point *points = malloc(n * sizeof(Point));
    if (points == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        return EXIT_FAILURE;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%lf %lf", &points[i].x, &points[i].y) != 2) {
            fprintf(stderr, "Invalid point input!\n");
            free(points);
            return EXIT_FAILURE;
        }
    }

    convexHull(points, n);
    
    // Free the allocated memory
    free(points);
    return 0;
}