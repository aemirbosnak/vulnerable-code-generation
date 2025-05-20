//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

// Function to determine the orientation of the triplet (p, q, r)
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counter clock wise
}

// Function to find the convex hull of a set of points
void convexHull(Point points[], int n) {
    if (n < 3) return; // Convex hull is not possible with less than 3 points

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    printf("The points in the convex hull are:\n");

    do {
        // Add the current point to the result
        printf("(%d, %d) ", points[p].x, points[p].y);

        q = (p + 1) % n; // Next point in the hull
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than current q, then update q
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        // Now q is the most counterclockwise point with respect to p
        // Set p as q for next iteration
        p = q;

    } while (p != l); // While we don't come to first point

    printf("\n");
}

// Function to read points from user
void readPoints(Point points[], int *n) {
    printf("Enter the number of points: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

int main() {
    Point points[100]; // Maximum of 100 points
    int n;

    readPoints(points, &n);
    convexHull(points, n);
    
    return 0;
}