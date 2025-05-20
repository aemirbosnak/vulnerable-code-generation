//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: content
#include <stdio.h>
#include <math.h>

// Define a Point structure to hold coordinates
typedef struct {
    float x;
    float y;
} Point;

// Define a Line structure to hold slope and y-intercept
typedef struct {
    float slope;
    float yIntercept;
} Line;

// Function to calculate the distance between two points
float distanceBetweenPoints(Point p1, Point p2) {
    float xDist = p2.x - p1.x;
    float yDist = p2.y - p1.y;
    return sqrt(pow(xDist, 2) + pow(yDist, 2));
}

// Function to calculate the slope of a line
float slopeOfLine(Point p1, Point p2) {
    float yDist = p2.y - p1.y;
    float xDist = p2.x - p1.x;
    if (xDist == 0) {
        return INFINITY;    // Handle divide by zero error for vertical lines
    } else {
        return yDist / xDist;
    }
}

// Function to calculate the y-intercept of a line
float yInterceptOfLine(Point p1, Point p2) {
    float slope = slopeOfLine(p1, p2);
    if (isinf(slope)) {
        return NAN;         // Handle vertical lines that don't have a y-intercept
    } else {
        float yInt = p1.y - (slope * p1.x);
        return yInt;
    }
}

// Function to calculate the midpoint of a line segment
Point midpointOfLine(Point p1, Point p2) {
    float xMid = (p1.x + p2.x) / 2;
    float yMid = (p1.y + p2.y) / 2;
    return (Point){xMid, yMid};
}

// Function to calculate the intersection point of two lines
Point intersectionOfLines(Line line1, Line line2) {
    float xInt, yInt;
    if (isinf(line1.slope)) {
        xInt = -line1.yIntercept;
        yInt = (line2.slope * xInt) + line2.yIntercept;
    } else if (isinf(line2.slope)) {
        xInt = -line2.yIntercept;
        yInt = (line1.slope * xInt) + line1.yIntercept;
    } else {
        xInt = (line2.yIntercept - line1.yIntercept) / (line1.slope - line2.slope);
        yInt = (line1.slope * xInt) + line1.yIntercept;
    }
    return (Point){xInt, yInt};
}

int main() {
    // Test the functions with some sample points and lines
    Point p1 = {2, 3};
    Point p2 = {5, 8};
    Point p3 = {-1, 4};

    float dist = distanceBetweenPoints(p1, p2);
    printf("Distance between (%.1f, %.1f) and (%.1f, %.1f) is %.2f\n", p1.x, p1.y, p2.x, p2.y, dist);

    float slope = slopeOfLine(p1, p2);
    printf("Slope of the line passing through (%.1f, %.1f) and (%.1f, %.1f) is %.2f\n", p1.x, p1.y, p2.x, p2.y, slope);

    float yInt = yInterceptOfLine(p1, p2);
    printf("Y-intercept of the line passing through (%.1f, %.1f) and (%.1f, %.1f) is %.2f\n", p1.x, p1.y, p2.x, p2.y, yInt);

    Point midpt = midpointOfLine(p1, p2);
    printf("Midpoint of the line passing through (%.1f, %.1f) and (%.1f, %.1f) is (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y, midpt.x, midpt.y);

    Line line1 = {1.5, -2};
    Line line2 = {-0.5, 5};
    Point intPt = intersectionOfLines(line1, line2);
    printf("Intersection point of the lines y = %.2fx + %.2f and y = %.2fx + %.2f is (%.2f, %.2f)\n", line1.slope, line1.yIntercept, line2.slope, line2.yIntercept, intPt.x, intPt.y);

    return 0;
}