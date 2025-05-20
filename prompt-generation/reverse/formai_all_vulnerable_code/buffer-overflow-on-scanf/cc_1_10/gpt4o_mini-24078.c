//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

// Structure to hold a point in 2D space
typedef struct {
    float x;
    float y;
} Point;

// Function to calculate the distance between two points
float distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to find the centroid of a set of points
Point findCentroid(Point points[], int numPoints) {
    Point centroid = {0, 0};
    for (int i = 0; i < numPoints; i++) {
        centroid.x += points[i].x;
        centroid.y += points[i].y;
    }
    centroid.x /= numPoints;
    centroid.y /= numPoints;
    return centroid;
}

// Function to print the points
void printPoints(Point points[], int numPoints) {
    printf("Points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
}

// Function to sort points based on X coordinates
int compare(const void *a, const void *b) {
    Point pointA = *(Point *)a;
    Point pointB = *(Point *)b;
    return (pointA.x > pointB.x) ? 1 : -1;
}

// Main function to demonstrate the geometric algorithms
int main() {
    Point points[MAX_POINTS];
    int numPoints;
    float range;

    // Input number of points
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);
    if (numPoints > MAX_POINTS || numPoints <= 0) {
        printf("Invalid number of points!\n");
        return 1;
    }

    // Input points
    for (int i = 0; i < numPoints; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    // Print the points
    printPoints(points, numPoints);

    // Find the centroid
    Point centroid = findCentroid(points, numPoints);
    printf("Centroid: (%.2f, %.2f)\n", centroid.x, centroid.y);

    // Sort the points
    qsort(points, numPoints, sizeof(Point), compare);
    printf("Sorted Points by X coordinates:\n");
    printPoints(points, numPoints);

    // Calculate the range of x and y values
    float minX = points[0].x, maxX = points[0].x;
    float minY = points[0].y, maxY = points[0].y;

    for (int i = 1; i < numPoints; i++) {
        if (points[i].x < minX) minX = points[i].x;
        if (points[i].x > maxX) maxX = points[i].x;
        if (points[i].y < minY) minY = points[i].y;
        if (points[i].y > maxY) maxY = points[i].y;
    }
    
    range = fmax(maxX - minX, maxY - minY);
    printf("Range of the points: %.2f\n", range);

    // Calculate distances between each pair of points
    printf("Distances between each pair of points:\n");
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            float dist = distance(points[i], points[j]);
            printf("Distance between Point %d and Point %d: %.2f\n", i + 1, j + 1, dist);
        }
    }

    return 0;
}