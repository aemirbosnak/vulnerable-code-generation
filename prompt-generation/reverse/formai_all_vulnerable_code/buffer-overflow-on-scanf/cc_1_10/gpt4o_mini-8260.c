//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

// Function declarations
void readPoints(Point **points, int *n);
void printConvexHull(Point *hull, int n);
int orientation(Point p, Point q, Point r);
void findConvexHull(Point *points, int n);

// Main function entrace
int main() {
    Point *points = NULL;
    int n = 0;
    
    // Let the adventure begin
    readPoints(&points, &n);
    findConvexHull(points, n);
    
    // Freeing allocated memory
    free(points);
    return 0;
}

// Function to read points from the user
void readPoints(Point **points, int *n) {
    printf("Enter the number of points: ");
    scanf("%d", n);
    
    *points = (Point *)malloc(*n * sizeof(Point));
    
    printf("Enter the points (x and y):\n");
    for (int i = 0; i < *n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &(*points)[i].x, &(*points)[i].y);
    }
}

// Function to print the points forming the convex hull
void printConvexHull(Point *hull, int n) {
    printf("The points forming the Convex Hull are:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", hull[i].x, hull[i].y);
    }
    printf("\n");
}

// Function to find the orientation of the ordered triplet (p, q, r)
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counter-clock wise
}

// Function to find the convex hull using the Gift Wrapping algorithm
void findConvexHull(Point *points, int n) {
    if (n < 3) {
        printf("Convex Hull not possible with less than 3 points.\n");
        return;
    }

    // Initialize Result
    Point *hull = (Point *)malloc(n * sizeof(Point));
    int hullIndex = 0;

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost, q;
    do {
        // Add current point to the hull
        hull[hullIndex++] = points[p];

        // Search for a point ‘q’ such that orientation(p, x, q) is counterclockwise
        // If there are multiple points, select the furthest one
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        // Set p as q for next iteration
        p = q;

    } while (p != leftmost); // While we don't come to first point

    // Print results
    printConvexHull(hull, hullIndex);
    // Free memory allocated for hull
    free(hull);
}