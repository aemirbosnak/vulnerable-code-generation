//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

// Function to find the orientation of the ordered triplet (p, q, r)
// Returns:
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Comparison function used by qsort to sort points based on polar angle
int compare(const void* vp1, const void* vp2) {
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;
    
    return p1->x - p2->x; // Sort by x-coordinate
}

// Function to calculate the convex hull using the Graham scan algorithm
void convexHull(Point points[], int n) {
    // Find the point with the lowest y-coordinate (and the leftmost point in case of a tie)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = y;
            min = i;
        }
    }
    // Place the lowest point at the first position
    Point temp = points[0];
    points[0] = points[min];
    points[min] = temp;

    // Sort points based on polar angle with the first point
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push the first three points on it
    Point hull[n];
    int hullIndex = 0;
    hull[hullIndex++] = points[0];
    hull[hullIndex++] = points[1];
    hull[hullIndex++] = points[2];

    // Process remaining points
    for (int i = 3; i < n; i++) {
        // While the last two points in the stack and the current point make a non-left turn
        while (hullIndex > 1 && orientation(hull[hullIndex - 2], hull[hullIndex - 1], points[i]) != 2) {
            hullIndex--; // Pop from stack
        }
        hull[hullIndex++] = points[i]; // Push current point to the stack
    }

    // Print the Convex Hull
    printf("The points in the Convex Hull are:\n");
    for (int i = 0; i < hullIndex; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Main function to demonstrate the convex hull algorithm
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    if (n < 3) {
        printf("Convex hull is not possible with less than 3 points.\n");
        return 0;
    }

    Point* points = (Point*)malloc(n * sizeof(Point));
    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);
    
    free(points);
    return 0;
}