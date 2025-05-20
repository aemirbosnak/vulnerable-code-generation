//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the centroid of an array of points
Point calculateCentroid(Point points[], int n) {
    Point centroid;
    double sumX = 0.0;
    double sumY = 0.0;

    for (int i = 0; i < n; i++) {
        sumX += points[i].x;
        sumY += points[i].y;
    }

    centroid.x = sumX / n;
    centroid.y = sumY / n;

    return centroid;
}

// Function to print the geometric report
void printReport(Point points[], int n, Point centroid) {
    printf("Geometric Report:\n");
    printf("--------------------\n");
    printf("Number of Points: %d\n", n);
    printf("Points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
    printf("\nCentroid: (%.2f, %.2f)\n", centroid.x, centroid.y);
    printf("--------------------\n");
}

// Function to generate random points
void generateRandomPoints(Point points[], int n, double maxX, double maxY) {
    for (int i = 0; i < n; i++) {
        points[i].x = (double)(rand() % (int)(maxX * 100)) / 100;
        points[i].y = (double)(rand() % (int)(maxY * 100)) / 100;
    }
}

int main() {
    int n;
    double maxX, maxY;

    // Initialize random seed
    srand((unsigned int) time(NULL));

    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the maximum X value: ");
    scanf("%lf", &maxX);
    printf("Enter the maximum Y value: ");
    scanf("%lf", &maxY);

    // Validate input
    if (n <= 0 || maxX <= 0 || maxY <= 0) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    // Allocate memory for points
    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation error. Exiting...\n");
        return 1;
    }

    // Generate random points
    generateRandomPoints(points, n, maxX, maxY);

    // Calculate the centroid
    Point centroid = calculateCentroid(points, n);

    // Print the report
    printReport(points, n, centroid);

    // Free allocated memory
    free(points);

    return 0;
}