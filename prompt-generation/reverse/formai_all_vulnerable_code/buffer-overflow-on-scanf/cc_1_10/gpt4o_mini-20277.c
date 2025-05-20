//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_POINTS];
    int vertexCount;
} Polygon;

// Function to compute the area of a polygon using the Shoelace theorem
double calculateArea(Polygon* polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->vertexCount; i++) {
        int j = (i + 1) % polygon->vertexCount; // Next vertex (wrap around)
        area += (polygon->vertices[i].x * polygon->vertices[j].y);
        area -= (polygon->vertices[j].x * polygon->vertices[i].y);
    }
    return fabs(area / 2.0);
}

// Function to check if a point is inside the polygon using ray-casting algorithm
int isPointInPolygon(Polygon* polygon, Point p) {
    int count = 0;
    for (int i = 0; i < polygon->vertexCount; i++) {
        int j = (i + 1) % polygon->vertexCount;

        // Check if the point is on an edge
        if ((polygon->vertices[i].y > p.y) != (polygon->vertices[j].y > p.y) &&
            (p.x < (polygon->vertices[j].x - polygon->vertices[i].x) * (p.y - polygon->vertices[i].y) /
                    (polygon->vertices[j].y - polygon->vertices[i].y) + polygon->vertices[i].x)) {
            count++;
        }
    }
    return count % 2; // Return true if inside (odd count)
}

// Function to read polygon vertices from user
void readPolygon(Polygon* polygon) {
    printf("Enter number of vertices: ");
    scanf("%d", &polygon->vertexCount);

    for (int i = 0; i < polygon->vertexCount; i++) {
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &polygon->vertices[i].x, &polygon->vertices[i].y);
    }
}

// Function to print polygon vertices
void printPolygon(Polygon* polygon) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < polygon->vertexCount; i++) {
        printf("Vertex %d: (%.2lf, %.2lf)\n", i + 1, polygon->vertices[i].x, polygon->vertices[i].y);
    }
}

// Function to read a point and check if it's inside the polygon
void checkPointInPolygon(Polygon* polygon) {
    Point p;
    printf("Enter point coordinates (x y): ");
    scanf("%lf %lf", &p.x, &p.y);

    if (isPointInPolygon(polygon, p)) {
        printf("Point (%.2lf, %.2lf) is inside the polygon.\n", p.x, p.y);
    } else {
        printf("Point (%.2lf, %.2lf) is outside the polygon.\n", p.x, p.y);
    }
}

int main() {
    Polygon polygon;

    // Read polygon vertices from user
    readPolygon(&polygon);

    // Print the polygon vertices
    printPolygon(&polygon);

    // Calculate and display the area of the polygon
    double area = calculateArea(&polygon);
    printf("Area of the polygon: %.2lf\n", area);

    // Check a point against the polygon
    checkPointInPolygon(&polygon);

    return 0;
}