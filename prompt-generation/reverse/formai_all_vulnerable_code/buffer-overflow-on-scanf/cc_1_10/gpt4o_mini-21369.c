//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

// Function to determine the orientation of the triplet (p, q, r)
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : (val > 0) ? 1 : 2;
}

// Function to get the convex hull using the Gift Wrapping algorithm
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points\n");
        return;
    }

    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    printf("Convex Hull points:\n");
    do {
        printf("(%d, %d)\n", points[p].x, points[p].y);
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        
        p = q;
    } while (p != l);
}

// Function to read points from user input
void readPoints(Point points[], int *n) {
    printf("Enter number of points: ");
    scanf("%d", n);
    
    printf("Enter the points (x y format):\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

int main() {
    Point points[100]; // Array to hold up to 100 points
    int n;

    readPoints(points, &n);
    convexHull(points, n);
    
    return 0;
}