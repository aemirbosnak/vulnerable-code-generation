//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

// Point struct to hold x and y coordinates
typedef struct {
    double x;
    double y;
} Point;

// Find orientation of ordered triplet (p1, p2, p3)
// Return 0 if collinear, 1 if clockwise, and 2 if counterclockwise
int orientation(Point p1, Point p2, Point p3) {
    double area = (p2.y - p1.y) * (p3.x - p2.x)
                - (p2.x - p1.x) * (p3.y - p2.y);
    if (area == 0) return 0;
    return (area > 0) ? 1 : 2;
}

// Main function to find convex hull of a set of n points
void jarvis_convex_hull(Point points[], int n) {
    // Initialize output array of hull points
    Point hull[MAX_POINTS];
    int hull_size = 0;

    // Find leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) leftmost = i;
    }

    // Start from leftmost point and keep moving counterclockwise
    int current = leftmost;
    do {
        // Add current point to hull
        hull[hull_size++] = points[current];

        // Find next point in hull by checking all other points
        int next = (current + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[current], points[i], points[next]) == 2) {
                next = i;
            }
        }

        // Update current point for next iteration
        current = next;
    } while (current != leftmost);

    // Output vertices of hull in clockwise order
    for (int i = hull_size - 1; i >= 0; i--) {
        printf("(%g, %g)\n", hull[i].x, hull[i].y);
    }
}

// Main program to prompt user for point inputs and call Jarvis algorithm
int main() {
    // Prompt user for number of points
    int n;
    printf("Enter number of points (maximum of %d): ", MAX_POINTS);
    scanf("%d", &n);

    // Prompt user for coordinates of each point
    Point points[MAX_POINTS];
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates of point %d (x, y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Find convex hull and output vertices
    printf("Convex hull vertices:\n");
    jarvis_convex_hull(points, n);

    return 0;
}