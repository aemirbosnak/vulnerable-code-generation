//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a point in 2D space
typedef struct point {
    double x;
    double y;
} point;

// Define the structure of a line segment
typedef struct line_segment {
    point p1;
    point p2;
} line_segment;

// Function to calculate the distance between two points
double distance(point p1, point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to check if a point is on a line segment
int is_on_line_segment(point p, line_segment l) {
    // Check if the point is on the same line as the line segment
    if ((l.p2.y - l.p1.y) * (p.x - l.p1.x) != (l.p2.x - l.p1.x) * (p.y - l.p1.y)) {
        return 0;
    }

    // Check if the point is between the endpoints of the line segment
    if (p.x < fmin(l.p1.x, l.p2.x) || p.x > fmax(l.p1.x, l.p2.x)) {
        return 0;
    }

    if (p.y < fmin(l.p1.y, l.p2.y) || p.y > fmax(l.p1.y, l.p2.y)) {
        return 0;
    }

    return 1;
}

// Function to find the intersection point of two line segments
point intersection_point(line_segment l1, line_segment l2) {
    // Calculate the slope of the line segments
    double m1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
    double m2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);

    // Check if the line segments are parallel
    if (m1 == m2) {
        return (point){-1, -1};
    }

    // Calculate the intersection point
    double x = ((m2 * l2.p1.x) - (m1 * l1.p1.x) + (l1.p1.y - l2.p1.y)) / (m2 - m1);
    double y = (m1 * (x - l1.p1.x)) + l1.p1.y;

    return (point){x, y};
}

// Function to test the geometric algorithms
int main() {
    // Create two line segments
    line_segment l1 = {{0, 0}, {10, 10}};
    line_segment l2 = {{5, 0}, {5, 10}};

    // Check if the line segments intersect
    point intersection = intersection_point(l1, l2);
    if (intersection.x != -1 && intersection.y != -1) {
        printf("The line segments intersect at the point (%f, %f).\n", intersection.x, intersection.y);
    } else {
        printf("The line segments do not intersect.\n");
    }

    // Create a point
    point p = {5, 5};

    // Check if the point is on the first line segment
    if (is_on_line_segment(p, l1)) {
        printf("The point (%f, %f) is on the first line segment.\n", p.x, p.y);
    } else {
        printf("The point (%f, %f) is not on the first line segment.\n", p.x, p.y);
    }

    // Check if the point is on the second line segment
    if (is_on_line_segment(p, l2)) {
        printf("The point (%f, %f) is on the second line segment.\n", p.x, p.y);
    } else {
        printf("The point (%f, %f) is not on the second line segment.\n", p.x, p.y);
    }

    return 0;
}