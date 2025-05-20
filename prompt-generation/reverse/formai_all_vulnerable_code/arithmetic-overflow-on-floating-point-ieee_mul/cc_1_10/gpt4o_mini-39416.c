//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to hold a point in Cartesian coordinates
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to determine if a point is within the bounds of a rectangle
int isPointInRectangle(Point p, Point bottomLeft, Point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x &&
            p.y >= bottomLeft.y && p.y <= topRight.y);
}

// Function to find the area of a triangle given three points
double calculateTriangleArea(Point p1, Point p2, Point p3) {
    return fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

// Function to find the centroid of a triangle given three points
Point calculateCentroid(Point p1, Point p2, Point p3) {
    Point centroid;
    centroid.x = (p1.x + p2.x + p3.x) / 3;
    centroid.y = (p1.y + p2.y + p3.y) / 3;
    return centroid;
}

int main() {
    // Define a rectangle using bottom left and top right corners
    Point bottomLeft = {0.0, 0.0};
    Point topRight = {5.0, 5.0};

    // Cluster of random points
    Point points[10];
    int i;
    for (i = 0; i < 10; i++) {
        points[i].x = (rand() % 10); // Generates random x in range [0,9]
        points[i].y = (rand() % 10); // Generates random y in range [0,9]
    }

    printf("Points generated:\n");
    for (i = 0; i < 10; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }

    // Count how many points are within the rectangle
    int insideCount = 0;
    for (i = 0; i < 10; i++) {
        if (isPointInRectangle(points[i], bottomLeft, topRight)) {
            insideCount++;
        }
    }

    printf("Number of points inside the rectangle: %d\n", insideCount);

    // Define triangle points
    Point p1 = {0.0, 0.0};
    Point p2 = {5.0, 0.0};
    Point p3 = {0.0, 5.0};

    // Calculate the area of the triangle
    double triangleArea = calculateTriangleArea(p1, p2, p3);
    printf("Area of the triangle formed by points (0,0), (5,0), (0,5): %.2f\n", triangleArea);

    // Calculate the centroid of the triangle
    Point centroid = calculateCentroid(p1, p2, p3);
    printf("Centroid of the triangle: (%.2f, %.2f)\n", centroid.x, centroid.y);

    // Calculate distance between two points
    double distance = calculateDistance(p1, p2);
    printf("Distance between point (0,0) and (5,0): %.2f\n", distance);

    return 0;
}