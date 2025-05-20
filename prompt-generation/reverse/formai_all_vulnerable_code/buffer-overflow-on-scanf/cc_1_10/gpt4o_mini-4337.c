//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_POINTS 100
#define PI 3.14159265

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int count;
} Polygon;

// Function to set a point
void setPoint(Polygon *poly, int index, double x, double y) {
    if (index >= 0 && index < MAX_POINTS) {
        poly->points[index].x = x;
        poly->points[index].y = y;
        poly->count++;
    } else {
        printf("Index out of bounds!\n");
    }
}

// Function to find the area of the polygon using the shoelace formula
double calculateArea(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count; // Next vertex
        area += (poly->points[i].x * poly->points[j].y);
        area -= (poly->points[j].x * poly->points[i].y);
    }
    area = fabs(area) / 2.0;
    return area;
}

// Function to determine if a point is inside the polygon using ray-casting algorithm
bool isPointInside(Polygon *poly, Point p) {
    int i, j;
    bool inside = false;

    for (i = 0, j = poly->count - 1; i < poly->count; j = i++) {
        if (((poly->points[i].y > p.y) != (poly->points[j].y > p.y)) &&
            (p.x < (poly->points[j].x - poly->points[i].x) * (p.y - poly->points[i].y) / (poly->points[j].y - poly->points[i].y) + poly->points[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

// Function to print the polygon's vertices
void printPolygon(Polygon *poly) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < poly->count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i, poly->points[i].x, poly->points[i].y);
    }
}

int main() {
    Polygon polygon = { .count = 0 };
    int numOfVertices;
    double x, y;
    
    printf("Enter the number of vertices for the polygon: ");
    scanf("%d", &numOfVertices);
    
    for (int i = 0; i < numOfVertices; i++) {
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        setPoint(&polygon, i, x, y);
    }
    
    printPolygon(&polygon);
    
    double area = calculateArea(&polygon);
    printf("Area of the polygon: %.2f\n", area);
    
    Point testPoint;
    printf("Enter a point to test if it's inside the polygon (x y): ");
    scanf("%lf %lf", &testPoint.x, &testPoint.y);
    
    if (isPointInside(&polygon, testPoint)) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", testPoint.x, testPoint.y);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", testPoint.x, testPoint.y);
    }
    
    return 0;
}