//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point structure
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to determine if the points A, B, and C are in a counter-clockwise order
int orientation(Point A, Point B, Point C) {
    double val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);
    if (val > 0) return 1;    // Clockwise
    if (val < 0) return 2;    // Counter-clockwise
    return 0;                 // Collinear
}

// Function to calculate the convex hull using the Jarvis March algorithm
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible with less than 3 points.\n");
        return;
    }

    int l = 0; // Initialize leftmost point
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do {
        printf("Point (%lf, %lf) is part of the convex hull.\n", points[p].x, points[p].y);
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != l);
}

// Function to read points from the user
void readPoints(Point points[], int *n) {
    printf("Enter number of points: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

// Function to display all points
void displayPoints(Point points[], int n) {
    printf("List of points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%lf, %lf)\n", i + 1, points[i].x, points[i].y);
    }
}

// The main function of the program
int main() {
    Point points[100]; // Array to hold points
    int n;            // Number of points

    // Read points from user
    readPoints(points, &n);

    // Display the entered points
    displayPoints(points, n);

    // Calculate and display the convex hull
    printf("\nCalculating Convex Hull...\n");
    convexHull(points, n);

    return 0;
}