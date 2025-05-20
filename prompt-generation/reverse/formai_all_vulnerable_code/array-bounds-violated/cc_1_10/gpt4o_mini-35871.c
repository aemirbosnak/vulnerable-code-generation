//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

// Function to compare two points based on their y-coordinate
// In case of a tie, compare based on x-coordinate
int compare(const void *p1, const void *p2) {
    Point *pt1 = (Point *)p1;
    Point *pt2 = (Point *)p2;

    if (pt1->y != pt2->y) {
        return (pt1->y > pt2->y) ? 1 : -1;
    }
    return (pt1->x > pt2->x) ? 1 : -1;
}

// Function to calculate the orientation of the triplet (p, q, r)
// Returns a positive value if r is on the left of pq, negative if on the right, and zero if collinear
double orientation(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

// Function to find the convex hull using the Graham scan method
void convexHull(Point *points, int n) {
    // Step 1: Find the point with the lowest y-coordinate
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y || 
           (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    }
    
    // Step 2: Move the lowest point to the start
    Point temp = points[0];
    points[0] = points[minIndex];
    points[minIndex] = temp;

    // Step 3: Sort points based on the angle made with the first point
    qsort(points + 1, n - 1, sizeof(Point), compare);

    // Step 4: Create an empty stack to store the convex hull points
    Point stack[n];
    int top = -1;

    // Step 5: Push the first three points onto the stack
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    // Step 6: Process the remaining n-3 points
    for (int i = 3; i < n; i++) {
        while (top > 0 && orientation(stack[top - 1], stack[top], points[i]) <= 0) {
            top--;  // Pop from stack
        }
        stack[++top] = points[i];  // Push current point onto stack
    }

    // Step 7: Print the points present in the convex hull
    printf("The points in the convex hull are:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%lf, %lf)\n", stack[i].x, stack[i].y);
    }
}

int main() {
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    free(points);  // Free the allocated memory
    return 0;
}