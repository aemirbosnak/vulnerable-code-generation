//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: future-proof
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
    int size;
} Polygon;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to add a point to the polygon
void addPoint(Polygon *polygon, double x, double y) {
    if (polygon->size >= MAX_POINTS) {
        printf("Maximum number of points reached.\n");
        return;
    }
    polygon->points[polygon->size].x = x;
    polygon->points[polygon->size].y = y;
    polygon->size++;
}

// Function to calculate the perimeter of the polygon
double calculatePerimeter(Polygon *polygon) {
    double perimeter = 0;
    for (int i = 0; i < polygon->size; i++) {
        perimeter += distance(polygon->points[i], polygon->points[(i + 1) % polygon->size]);
    }
    return perimeter;
}

// Function to calculate the area of the polygon using the Shoelace formula
double calculateArea(Polygon *polygon) {
    double area = 0;
    for (int i = 0; i < polygon->size; i++) {
        area += (polygon->points[i].x * polygon->points[(i + 1) % polygon->size].y);
        area -= (polygon->points[(i + 1) % polygon->size].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

// Function to print the polygon points
void printPolygon(Polygon *polygon) {
    printf("Polygon Points:\n");
    for (int i = 0; i < polygon->size; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

// Function to clear the polygon points
void clearPolygon(Polygon *polygon) {
    polygon->size = 0;
}

int main() {
    Polygon polygon;
    polygon.size = 0;

    // Sample Input
    double x, y;
    printf("Enter points of the polygon (x y). Type 'exit' to stop:\n");
    while (1) {
        printf("Point %d: ", polygon.size + 1);
        if (scanf("%lf %lf", &x, &y) != 2) {
            break; // Exit when not receiving valid input
        }
        addPoint(&polygon, x, y);
    }

    // Calculate and display the perimeter
    double perimeter = calculatePerimeter(&polygon);
    printf("Perimeter of the polygon: %.2f\n", perimeter);

    // Calculate and display the area
    double area = calculateArea(&polygon);
    printf("Area of the polygon: %.2f\n", area);

    // Print the points of the polygon
    printPolygon(&polygon);

    // Clear the polygon
    clearPolygon(&polygon);
    printf("Polygon cleared.\n");

    return 0;
}