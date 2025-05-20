//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

// Function to find the orientation of the triplet (p, q, r).
// Returns:
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to compare two points for sorting.
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x == p2->x) ? (p1->y - p2->y) : (p1->x - p2->x);
}

// Function to find the convex hull of a set of points.
void convexHull(Point points[], int n) {
    if (n < 3) return; // Convex hull is not possible with less than 3 points

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    int p = l, q;
    printf("Convex Hull points:\n");
    do {
        // Print this point
        printf("(%d, %d)\n", points[p].x, points[p].y);

        // Search for a point 'q' such that orientation(p, x, q) is counterclockwise
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        p = q;

    } while (p != l); // While we don't come to first point
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
    
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Sort the points lexicographically (by x, then by y)
    qsort(points, n, sizeof(Point), compare);

    // Compute the convex hull
    convexHull(points, n);

    // Free allocated memory
    free(points);
    return 0;
}