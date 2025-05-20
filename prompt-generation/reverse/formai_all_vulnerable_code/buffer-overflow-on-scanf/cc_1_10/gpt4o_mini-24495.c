//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the area of a polygon
double calculateArea(Point *polygon, int n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // Next vertex
        area += polygon[i].x * polygon[j].y;
        area -= polygon[j].x * polygon[i].y;
    }
    return fabs(area) / 2.0;
}

// Function to check if a point lies inside a polygon using ray-casting algorithm
int isPointInsidePolygon(Point *polygon, int n, Point testPoint) {
    int count = 0, i, j;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > testPoint.y) != (polygon[j].y > testPoint.y)) &&
            (testPoint.x < (polygon[j].x - polygon[i].x) * (testPoint.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            count++;
        }
    }
    return count % 2; // Ray is cast, if odd count then it's inside
}

// Function to input the vertices of the polygon
void inputPolygon(Point **polygon, int *n) {
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", n);

    *polygon = (Point *)malloc(*n * sizeof(Point));

    printf("Enter the coordinates of the vertices (x y):\n");
    for (int i = 0; i < *n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%lf %lf", &(*polygon)[i].x, &(*polygon)[i].y);
    }
}

// Function to input the point to be checked
void inputPoint(Point *testPoint) {
    printf("Enter the point (x y): ");
    scanf("%lf %lf", &testPoint->x, &testPoint->y);
}

// Main function
int main() {
    Point *polygon;
    Point testPoint;
    int n;

    // Input polygon and point details
    inputPolygon(&polygon, &n);
    inputPoint(&testPoint);

    // Compute area of the polygon
    double area = calculateArea(polygon, n);
    printf("Area of the polygon: %.2f\n", area);

    // Check if the point is inside the polygon
    if (isPointInsidePolygon(polygon, n, testPoint)) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", testPoint.x, testPoint.y);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", testPoint.x, testPoint.y);
    }

    // Clean up
    free(polygon);
    return 0;
}