//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

Point points[MAX_POINTS];
int numPoints = 0;

// Function to read points from standard input
void readPoints() {
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);
    
    if (numPoints > MAX_POINTS || numPoints <= 0) {
        printf("Invalid number of points.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < numPoints; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

// Function to compute the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to find the closest pair of points
void closestPair(Point points[], int n) {
    double minDist = INFINITY;
    Point p1, p2;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    printf("The closest pair of points is: (%.2f, %.2f) and (%.2f, %.2f) with distance %.2f\n", 
           p1.x, p1.y, p2.x, p2.y, minDist);
}

// Function to calculate the area of a triangle given by three points
double triangleArea(Point a, Point b, Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
}

// Function to check if three points are collinear
int areCollinear(Point a, Point b, Point c) {
    return triangleArea(a, b, c) == 0;
}

// Function to find the number of collinear points
void findCollinearPoints(Point points[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (areCollinear(points[i], points[j], points[k])) {
                    count++;
                }
            }
        }
    }

    printf("The number of unique sets of collinear points is: %d\n", count);
}

// Main function to execute the program
int main() {
    readPoints();

    closestPair(points, numPoints);
    findCollinearPoints(points, numPoints);

    return 0;
}