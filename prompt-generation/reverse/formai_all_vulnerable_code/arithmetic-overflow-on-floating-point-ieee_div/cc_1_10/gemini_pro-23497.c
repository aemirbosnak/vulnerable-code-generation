//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Structure to represent a line segment
typedef struct LineSegment {
    Point p1;
    Point p2;
} LineSegment;

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to check if two line segments intersect
int doIntersect(LineSegment l1, LineSegment l2) {
    // Check if the two line segments are parallel
    if ((l1.p2.x - l1.p1.x) * (l2.p2.y - l2.p1.y) == (l2.p2.x - l2.p1.x) * (l1.p2.y - l1.p1.y)) {
        return 0;
    }

    // Calculate the intersection point
    double x = ((l1.p2.x - l1.p1.x) * (l2.p2.y - l2.p1.y) - (l2.p2.x - l2.p1.x) * (l1.p2.y - l1.p1.y)) / ((l1.p2.x - l1.p1.x) * (l2.p1.y - l2.p2.y) - (l2.p2.x - l2.p1.x) * (l1.p1.y - l1.p2.y));
    double y = ((l1.p1.x - l1.p2.x) * (l2.p2.y - l2.p1.y) - (l2.p2.x - l2.p1.x) * (l1.p1.y - l1.p2.y)) / ((l1.p1.x - l1.p2.x) * (l2.p1.y - l2.p2.y) - (l2.p2.x - l2.p1.x) * (l1.p1.y - l1.p2.y));

    // Check if the intersection point is on both line segments
    if (x >= 0 && x <= 1 && y >= 0 && y <= 1) {
        return 1;
    }

    return 0;
}

int main() {
    // Create two line segments
    LineSegment l1 = {{0, 0}, {1, 1}};
    LineSegment l2 = {{1, 0}, {0, 1}};

    // Check if the two line segments intersect
    int intersect = doIntersect(l1, l2);

    // Print the result
    if (intersect) {
        printf("The two line segments intersect.\n");
    } else {
        printf("The two line segments do not intersect.\n");
    }

    return 0;
}