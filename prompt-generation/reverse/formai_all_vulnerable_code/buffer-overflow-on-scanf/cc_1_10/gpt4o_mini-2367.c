//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

// Function Prototypes
Polygon* createPolygon(int size);
void destroyPolygon(Polygon *polygon);
void addPoint(Polygon *polygon, int index, int x, int y);
void computeArea(Polygon *polygon);
double distance(Point a, Point b);
void printPolygon(Polygon *polygon);

// Main Function
int main() {
    int numPoints;

    printf("Enter the number of points in the polygon (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);

    if (numPoints < 3 || numPoints > MAX_POINTS) {
        printf("Polygon must have at least 3 points and at most %d points.\n", MAX_POINTS);
        return 1;
    }

    Polygon *polygon = createPolygon(numPoints);
    for (int i = 0; i < numPoints; i++) {
        int x, y;
        printf("Enter point %d (x y): ", i + 1);
        scanf("%d %d", &x, &y);
        addPoint(polygon, i, x, y);
    }

    printPolygon(polygon);
    computeArea(polygon);
    destroyPolygon(polygon);

    return 0;
}

// Function to create a polygon
Polygon* createPolygon(int size) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->points = malloc(size * sizeof(Point));
    polygon->size = size;
    return polygon;
}

// Function to free polygon memory
void destroyPolygon(Polygon *polygon) {
    if (polygon) {
        free(polygon->points);
        free(polygon);
    }
}

// Function to add a point to a polygon
void addPoint(Polygon *polygon, int index, int x, int y) {
    polygon->points[index].x = x;
    polygon->points[index].y = y;
}

// Function to compute the area of the polygon using the Shoelace formula
void computeArea(Polygon *polygon) {
    double area = 0.0;
    int j = polygon->size - 1; // The last vertex is connected to the first

    for (int i = 0; i < polygon->size; i++) {
        area += (polygon->points[j].x + polygon->points[i].x) * (polygon->points[j].y - polygon->points[i].y);
        j = i; // j is previous vertex to i
    }

    area = fabs(area) / 2.0;
    printf("The area of the polygon is: %.2f\n", area);
}

// Function to calculate distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to print polygon points
void printPolygon(Polygon *polygon) {
    printf("Polygon points:\n");
    for (int i = 0; i < polygon->size; i++) {
        printf("Point %d: (%d, %d)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}