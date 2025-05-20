//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point
typedef struct {
    int x;
    int y;
} Point;

// Function to compare two points for sorting
int compare(const void *p1, const void *p2) {
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;

    if (point1->y != point2->y)
        return (point1->y - point2->y);
    return (point1->x - point2->x);
}

// Function to calculate the orientation of the ordered triplet (p, q, r)
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) 
        return 0;
    return (val > 0) ? 1 : 2; // 1: Clockwise, 2: Counterclockwise
}

// Function to return the convex hull of a set of points
void convexHull(Point points[], int n) {
    // Find the bottom-most point (or leftmost in case of tie)
    int minY = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < minY || 
           (points[i].y == minY && points[i].x < points[minIdx].x)) {
            minY = points[i].y;
            minIdx = i;
        }
    }

    // Place the bottom-most point at the beginning
    Point temp = points[0];
    points[0] = points[minIdx];
    points[minIdx] = temp;

    // Sort the points based on polar angle from the base point
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push first three points to it
    Point stack[n];
    int top = 0;

    stack[top++] = points[0];
    stack[top++] = points[1];
    stack[top++] = points[2];

    // Process the points
    for (int i = 3; i < n; i++) {
        while (top > 1 && orientation(stack[top - 2], stack[top - 1], points[i]) != 2) {
            top--;
        }
        stack[top++] = points[i];
    }

    // Print the convex hull points
    printf("Convex Hull:\n");
    for (int i = 0; i < top; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }
}

int main() {
    int n;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input the points
    printf("Enter the coordinates of the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Find and print the convex hull
    convexHull(points, n);

    // Free allocated memory
    free(points);
    return 0;
}