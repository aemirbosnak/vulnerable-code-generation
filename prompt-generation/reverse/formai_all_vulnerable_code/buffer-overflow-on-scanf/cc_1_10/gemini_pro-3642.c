//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Given a set of n points in the plane, find the minimum bounding box that contains all the points.
 *
 * The bounding box is represented by two points, the lower left corner and the upper right corner.
 */
typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point lower_left;
    Point upper_right;
} BoundingBox;

BoundingBox minimum_bounding_box(Point *points, int n) {
    // Initialize the bounding box to the first point.
    BoundingBox bbox = {points[0], points[0]};

    // Iterate over the remaining points and update the bounding box accordingly.
    for (int i = 1; i < n; i++) {
        if (points[i].x < bbox.lower_left.x) {
            bbox.lower_left.x = points[i].x;
        } else if (points[i].x > bbox.upper_right.x) {
            bbox.upper_right.x = points[i].x;
        }

        if (points[i].y < bbox.lower_left.y) {
            bbox.lower_left.y = points[i].y;
        } else if (points[i].y > bbox.upper_right.y) {
            bbox.upper_right.y = points[i].y;
        }
    }

    // Return the bounding box.
    return bbox;
}

int main() {
    // Get the number of points from the user.
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Allocate memory for the points.
    Point *points = malloc(n * sizeof(Point));

    // Get the points from the user.
    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Find the minimum bounding box.
    BoundingBox bbox = minimum_bounding_box(points, n);

    // Print the minimum bounding box.
    printf("The minimum bounding box is:\n");
    printf("Lower left corner: (%lf, %lf)\n", bbox.lower_left.x, bbox.lower_left.y);
    printf("Upper right corner: (%lf, %lf)\n", bbox.upper_right.x, bbox.upper_right.y);

    // Free the memory allocated for the points.
    free(points);

    return 0;
}