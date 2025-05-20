//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>

// Define a struct to hold the information for a point
struct Point {
    float x;
    float y;
};

// Define a struct to hold the information for a line segment
struct LineSegment {
    struct Point p1;
    struct Point p2;
};

// Function to calculate the length of a line segment
float calculateLength(struct LineSegment line) {
    float x_diff = line.p2.x - line.p1.x;
    float y_diff = line.p2.y - line.p1.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

// Function to calculate the intersection point of two line segments
struct Point calculateIntersectionPoint(struct LineSegment line1, struct LineSegment line2) {
    float x1 = line1.p1.x;
    float y1 = line1.p1.y;
    float x2 = line1.p2.x;
    float y2 = line1.p2.y;
    float x3 = line2.p1.x;
    float y3 = line2.p1.y;
    float x4 = line2.p2.x;
    float y4 = line2.p2.y;

    float det1 = (x1*y2 - y1*x2);
    float det2 = (x3*y4 - y3*x4);
    float det3 = ((x1-x2)*(y3-y4) - (y1-y2)*(x3-x4));

    struct Point intersection_point;

    intersection_point.x = ((det1*(x3-x4)) - ((x1-x2)*det2)) / det3;
    intersection_point.y = ((det1*(y3-y4)) - ((y1-y2)*det2)) / det3;

    return intersection_point;
}

int main() {
    struct Point p1 = {1, 2};
    struct Point p2 = {3, 4};
    struct Point p3 = {2, 1};
    struct Point p4 = {4, 3};

    struct LineSegment line1 = {p1, p2};
    struct LineSegment line2 = {p3, p4};

    float length1 = calculateLength(line1);
    float length2 = calculateLength(line2);

    printf("Line segment 1 has length: %f\n", length1);
    printf("Line segment 2 has length: %f\n", length2);

    struct Point intersection_point = calculateIntersectionPoint(line1, line2);

    printf("The intersection point of the two line segments is: (%f, %f)\n", intersection_point.x, intersection_point.y);

    return 0;
}