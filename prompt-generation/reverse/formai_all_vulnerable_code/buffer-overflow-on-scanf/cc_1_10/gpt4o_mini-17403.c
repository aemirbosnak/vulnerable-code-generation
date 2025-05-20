//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point
typedef struct {
    double x, y;
} Point;

// Function to compare two points
int compare(const void *p1, const void *p2) {
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;

    if (point1->y != point2->y)
        return (point1->y > point2->y) ? 1 : -1;
    return (point1->x > point2->x) ? 1 : -1;
}

// Function to find the orientation of the triplet (p, q, r)
// Returns 0 if collinear, 1 if clockwise, 2 if counterclockwise
int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Function to implement the Convex Hull algorithm using Graham's scan method
void convexHull(Point points[], int n) {
    // Find the point with the lowest y-coordinate (and leftmost if there are ties)
    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }

    // Place the found point at the beginning
    Point temp = points[0];
    points[0] = points[minIndex];
    points[minIndex] = temp;

    // Sort the points based on polar angle with the first point
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push the first three points onto it
    Point stack[n];
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    // Process the rest of the points
    for (int i = 3; i < n; i++) {
        while (top > 1 && orientation(stack[top - 1], stack[top], points[i]) != 2) {
            top--;
        }
        stack[++top] = points[i];
    }

    // Print the points in the Convex Hull
    printf("The Convex Hull points are:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%lf, %lf)\n", stack[i].x, stack[i].y);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Convex Hull is not possible with less than 3 points.\n");
        return 0;
    }

    Point points[n];
    printf("Enter the points (x y) format:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    convexHull(points, n);
    return 0;
}