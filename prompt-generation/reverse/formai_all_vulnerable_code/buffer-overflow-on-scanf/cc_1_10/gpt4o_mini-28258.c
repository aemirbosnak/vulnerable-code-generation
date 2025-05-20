//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int count;
} Polygon;

// Function to calculate the area of a polygon using the Shoelace theorem
double calculatePolygonArea(Polygon *polygon) {
    double area = 0.0;
    int j = polygon->count - 1;

    for (int i = 0; i < polygon->count; i++) {
        area += (polygon->points[j].x + polygon->points[i].x) * (polygon->points[j].y - polygon->points[i].y);
        j = i;  // j is previous vertex to i
    }
    
    return fabs(area) / 2.0;
}

// Function to check if a point is inside a polygon using ray casting algorithm
int isPointInsidePolygon(Point p, Polygon *polygon) {
    int i, j;
    int inside = 0;
    
    for (i = 0, j = polygon->count - 1; i < polygon->count; j = i++) {
        if ((polygon->points[i].y > p.y) != (polygon->points[j].y > p.y) &&
            (p.x < (polygon->points[j].x - polygon->points[i].x) * (p.y - polygon->points[i].y) / 
            (polygon->points[j].y - polygon->points[i].y) + polygon->points[i].x)) {
            inside = !inside;
        }
    }
    
    return inside;
}

// Function to create a polygon
void createPolygon(Polygon *polygon) {
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &polygon->count);
  
    if (polygon->count > MAX_POINTS || polygon->count < 3) {
        printf("Invalid number of points. Must be between 3 and %d.\n", MAX_POINTS);
        exit(EXIT_FAILURE);
    }

    printf("Enter the vertices (x y) of the polygon:\n");
    for (int i = 0; i < polygon->count; i++) {
        scanf("%lf %lf", &polygon->points[i].x, &polygon->points[i].y);
    }
}

// Function to print the polygon's vertices
void printPolygon(Polygon *polygon) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < polygon->count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

// Main function
int main() {
    Polygon polygon;
    Point testPoint;

    createPolygon(&polygon);
    printPolygon(&polygon);

    double area = calculatePolygonArea(&polygon);
    printf("Area of the polygon: %.2f\n", area);

    printf("Enter a point to check if it's inside (x y): ");
    scanf("%lf %lf", &testPoint.x, &testPoint.y);

    if (isPointInsidePolygon(testPoint, &polygon)) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", testPoint.x, testPoint.y);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", testPoint.x, testPoint.y);
    }

    return 0;
}