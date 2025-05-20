//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_VERTICES];
    int count;
} Polygon;

void addVertex(Polygon *polygon, double x, double y) {
    if (polygon->count < MAX_VERTICES) {
        polygon->vertices[polygon->count].x = x;
        polygon->vertices[polygon->count].y = y;
        polygon->count++;
    } else {
        printf("Max vertices limit reached!\n");
    }
}

double area(Polygon *polygon) {
    double area = 0.0;
    int j = polygon->count - 1; // The last vertex is the previous one to the first

    for (int i = 0; i < polygon->count; i++) {
        area += (polygon->vertices[j].x + polygon->vertices[i].x) * 
                (polygon->vertices[j].y - polygon->vertices[i].y);
        j = i; // j is previous vertex to i
    }
    return fabs(area) / 2.0;
}

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

void displayPolygon(Polygon *polygon) {
    printf("Polygon Vertices:\n");
    for (int i = 0; i < polygon->count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i+1, polygon->vertices[i].x, polygon->vertices[i].y);
    }
}

double perimeter(Polygon *polygon) {
    double perim = 0.0;
    for (int i = 0; i < polygon->count; i++) {
        perim += distance(polygon->vertices[i], polygon->vertices[(i + 1) % polygon->count]);
    }
    return perim;
}

int is_point_inside(Polygon *polygon, Point p) {
    int count = 0;
    for (int i = 0; i < polygon->count; i++) {
        Point v1 = polygon->vertices[i];
        Point v2 = polygon->vertices[(i + 1) % polygon->count];
        if ((v1.y > p.y) != (v2.y > p.y) && 
            (p.x < (v2.x - v1.x) * (p.y - v1.y) / (v2.y - v1.y) + v1.x)) {
            count++;
        }
    }
    return count % 2; // If count is odd, point is inside
}

void readPolygon(Polygon *polygon) {
    int numberOfVertices;
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numberOfVertices);
    if (numberOfVertices > MAX_VERTICES) {
        printf("Error: Max number of vertices is %d.\n", MAX_VERTICES);
        exit(1);
    }

    for (int i = 0; i < numberOfVertices; i++) {
        double x, y;
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        addVertex(polygon, x, y);
    }
}

int main() {
    Polygon polygon;
    polygon.count = 0;

    readPolygon(&polygon);
    displayPolygon(&polygon);

    double calculated_area = area(&polygon);
    double calculated_perimeter = perimeter(&polygon);
    
    printf("Area of the polygon: %.2f\n", calculated_area);
    printf("Perimeter of the polygon: %.2f\n", calculated_perimeter);

    Point test_point;
    printf("Enter a point (x y) to check if inside polygon: ");
    scanf("%lf %lf", &test_point.x, &test_point.y);

    if (is_point_inside(&polygon, test_point)) {
        printf("Point (%.2f, %.2f) is inside the polygon.\n", test_point.x, test_point.y);
    } else {
        printf("Point (%.2f, %.2f) is outside the polygon.\n", test_point.x, test_point.y);
    }

    return 0;
}