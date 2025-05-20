//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

// Function prototypes
void getPoints(Point points[], int n);
void displayPoints(Point points[], int n);
double calculateDistance(Point a, Point b);
int compare(const void *a, const void *b);
void closestPair(Point points[], int n);

int main() {
    int n;
    Point points[MAX_POINTS];

    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n < 2 || n > MAX_POINTS) {
        printf("Invalid number of points.\n");
        return 1;
    }

    getPoints(points, n);
    printf("\nPoints:\n");
    displayPoints(points, n);
    
    closestPair(points, n);

    return 0;
}

void getPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

void displayPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }
}

double calculateDistance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
    
    if (pointA->x < pointB->x) return -1;
    if (pointA->x > pointB->x) return 1;
    
    return 0; // points are equal
}

void closestPair(Point points[], int n) {
    double minDistance = INFINITY;
    Point point1, point2;

    // Sort the points based on x coordinates
    qsort(points, n, sizeof(Point), compare);

    // Check each pair for minimum distance
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = calculateDistance(points[i], points[j]);
            if (distance < minDistance) {
                minDistance = distance;
                point1 = points[i];
                point2 = points[j];
            }
        }
    }

    printf("\nThe closest pair of points is:\n");
    printf("Point 1: (%.2f, %.2f)\n", point1.x, point1.y);
    printf("Point 2: (%.2f, %.2f)\n", point2.x, point2.y);
    printf("Minimum Distance: %.2f\n", minDistance);
}