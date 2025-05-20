//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} Point;

// Function to compare two points based on their polar angle
int compare(const void *p1, const void *p2) {
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;
    return (point1->x > point2->x) - (point1->x < point2->x);
}

// Function to find the orientation of the ordered triplet (p, q, r)
// Returns 0 if collinear, 1 if clockwise, and 2 if counterclockwise
int orientation(Point p, Point q, Point r) {
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Function to compute the convex hull using Graham's scan algorithm
void convexHull(Point *points, int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    // Find the point with the lowest y-coordinate
    int ymin = 0;
    for (int i = 1; i < n; i++)
        if (points[i].y < points[ymin].y || (points[i].y == points[ymin].y && points[i].x < points[ymin].x))
            ymin = i;

    // Place the bottom-most point at the first position
    Point temp = points[0];
    points[0] = points[ymin];
    points[ymin] = temp;

    // Sort the remaining points based on polar angle with the first point
    qsort(points + 1, n - 1, sizeof(Point), compare);

    // Create an array to store the convex hull points
    Point *hull = malloc(n * sizeof(Point));
    int m = 0; // Index for hull array

    // Process the sorted points
    for (int i = 0; i < n; i++) {
        while (m >= 2 && orientation(hull[m - 2], hull[m - 1], points[i]) != 2) {
            m--; // Remove point
        }
        hull[m++] = points[i]; // Add current point to the hull
    }

    // Print the convex hull points
    printf("Convex Hull:\n");
    for (int i = 0; i < m; i++) {
        printf("(%f, %f)\n", hull[i].x, hull[i].y);
    }
    
    free(hull); // Free the dynamically allocated memory
}

// Main function to take input points and call convex hull function
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Dynamically allocate memory for points
    Point *points = malloc(n * sizeof(Point));
    
    // Input points
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    // Calculate and display the convex hull
    convexHull(points, n);

    // Free the allocated memory for points
    free(points);
    return 0;
}