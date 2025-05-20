//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define PI 3.14159265

typedef struct {
    double x;
    double y;
} Point;

// Function to compare two points based on polar angle
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    
    double angle1 = atan2(p1->y, p1->x);
    double angle2 = atan2(p2->y, p2->x);
    
    return (angle1 > angle2) - (angle1 < angle2);
}

// Function to calculate the area of the triangle formed by three points
double area(Point p1, Point p2, Point p3) {
    return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
}

// Graham scan algorithm to compute Convex Hull
void grahamScan(Point points[], int n) {
    // Find the point with the lowest y-coordinate
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[min_index].y || 
           (points[i].y == points[min_index].y && points[i].x < points[min_index].x)) {
            min_index = i;
        }
    }

    // Swap the lowest point with the first point
    Point temp = points[0];
    points[0] = points[min_index];
    points[min_index] = temp;

    // Sort points based on polar angles with respect to the lowest point
    qsort(points + 1, n - 1, sizeof(Point), compare);
    
    // Initialize the Convex Hull with the first three points
    Point *hull = (Point *)malloc(sizeof(Point) * (n + 1));
    int hull_size = 0;

    hull[hull_size++] = points[0];
    hull[hull_size++] = points[1];

    // Process the remaining points
    for (int i = 2; i < n; i++) {
        while (hull_size >= 2) {
            Point p1 = hull[hull_size - 2];
            Point p2 = hull[hull_size - 1];
            Point p3 = points[i];

            if (area(p1, p2, p3) <= 0) {
                hull_size--; // Remove the top point from the hull
            } else {
                break; // p3 is on the left of the line p1p2
            }
        }
        hull[hull_size++] = points[i];
    }

    // Print the Convex Hull points
    printf("Convex Hull points:\n");
    for (int i = 0; i < hull_size; i++) {
        printf("(%f, %f)\n", hull[i].x, hull[i].y);
    }

    free(hull);
}

// Function to generate random points
void generateRandomPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100; // Random x-coordinate from 0 to 99
        points[i].y = rand() % 100; // Random y-coordinate from 0 to 99
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    Point points[MAX_POINTS];
    int num_points;

    printf("Enter the number of random points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    if (num_points > MAX_POINTS) {
        printf("Number of points exceeds limit. Setting to maximum allowed %d.\n", MAX_POINTS);
        num_points = MAX_POINTS;
    }

    // Generate random points
    generateRandomPoints(points, num_points);
    printf("Random Points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("(%f, %f)\n", points[i].x, points[i].y);
    }

    // Compute the Convex Hull
    grahamScan(points, num_points);

    return 0;
}