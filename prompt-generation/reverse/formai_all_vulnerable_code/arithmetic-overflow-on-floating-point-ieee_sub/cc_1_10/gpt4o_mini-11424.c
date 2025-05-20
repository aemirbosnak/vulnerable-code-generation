//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *vertices;
    int vertexCount;
} Polygon;

Polygon* createPolygon(int count) {
    Polygon *poly = (Polygon*)malloc(sizeof(Polygon));
    poly->vertexCount = count;
    poly->vertices = (Point*)malloc(count * sizeof(Point));
    return poly;
}

void destroyPolygon(Polygon *poly) {
    free(poly->vertices);
    free(poly);
}

double calculateArea(Polygon *poly) {
    double area = 0.0;
    int j = poly->vertexCount - 1;  // last vertex is the previous one to the first

    for (int i = 0; i < poly->vertexCount; i++) {
        area += (poly->vertices[j].x + poly->vertices[i].x) * (poly->vertices[j].y - poly->vertices[i].y);
        j = i;  // j is previous vertex to i
    }
    return fabs(area / 2.0);
}

double calculatePerimeter(Polygon *poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->vertexCount; i++) {
        int next = (i + 1) % poly->vertexCount;
        double dx = poly->vertices[next].x - poly->vertices[i].x;
        double dy = poly->vertices[next].y - poly->vertices[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void inputPolygonVertices(Polygon *poly) {
    printf("Input the vertices of the polygon:\n");
    for (int i = 0; i < poly->vertexCount; i++) {
        printf("Vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &poly->vertices[i].x, &poly->vertices[i].y);
    }
}

void displayPolygon(Polygon *poly) {
    printf("\nVertices of the polygon:\n");
    for (int i = 0; i < poly->vertexCount; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

void menu() {
    printf("--------- Polygon Geometry Calculator ---------\n");
    printf("1. Input Polygon Vertices\n");
    printf("2. Calculate Area\n");
    printf("3. Calculate Perimeter\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice, vertexCount;
    
    printf("Enter number of vertices for the polygon: ");
    scanf("%d", &vertexCount);
    
    if (vertexCount < 3) {
        printf("A polygon must have at least 3 vertices.\n");
        return 1;
    }
    
    Polygon *polygon = createPolygon(vertexCount);

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputPolygonVertices(polygon);
                displayPolygon(polygon);
                break;
            case 2:
                printf("Area of the polygon: %.2f\n", calculateArea(polygon));
                break;
            case 3:
                printf("Perimeter of the polygon: %.2f\n", calculatePerimeter(polygon));
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    destroyPolygon(polygon);
    return 0;
}