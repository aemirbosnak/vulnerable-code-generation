//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: genius
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define MAX_SIDES 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_SIDES];
    int num_vertices;
} Polygon;

// Function prototypes
void inputPolygon(Polygon* poly);
void printPolygon(const Polygon* poly);
double calculateArea(const Polygon* poly);
double calculatePerimeter(const Polygon* poly);
double calculateTriangleArea(Point a, Point b, Point c);
int isPointInsidePolygon(const Polygon* poly, Point p);
void translatePolygon(Polygon* poly, double tx, double ty);
void rotatePolygon(Polygon* poly, double angleDegrees);

// Main function
int main() {
    Polygon poly;

    printf("Welcome to the Geometric Algorithm Program!\n");
    printf("Let's define a polygon.\n");
    
    inputPolygon(&poly);
    
    printf("\nYour Polygon:\n");
    printPolygon(&poly);
    
    double area = calculateArea(&poly);
    double perimeter = calculatePerimeter(&poly);
    
    printf("Area of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);
    
    Point p;
    printf("Enter a point (x y) to check if it is inside the polygon: ");
    scanf("%lf %lf", &p.x, &p.y);
    
    if (isPointInsidePolygon(&poly, p)) {
        printf("The point (%.2f, %.2f) is inside the polygon.\n", p.x, p.y);
    } else {
        printf("The point (%.2f, %.2f) is outside the polygon.\n", p.x, p.y);
    }

    double tx, ty;
    printf("Enter translation vector (tx ty): ");
    scanf("%lf %lf", &tx, &ty);
    translatePolygon(&poly, tx, ty);
    
    printf("Polygon after translation:\n");
    printPolygon(&poly);

    double angle;
    printf("Enter angle of rotation in degrees: ");
    scanf("%lf", &angle);
    rotatePolygon(&poly, angle);

    printf("Polygon after rotation:\n");
    printPolygon(&poly);
    
    return 0;
}

// Input polygon vertices
void inputPolygon(Polygon* poly) {
    printf("Enter the number of vertices (max %d): ", MAX_SIDES);
    scanf("%d", &poly->num_vertices);
    
    if (poly->num_vertices < 3 || poly->num_vertices > MAX_SIDES) {
        fprintf(stderr, "Invalid number of vertices! Must be between 3 and %d.\n", MAX_SIDES);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &poly->vertices[i].x, &poly->vertices[i].y);
    }
}

// Print polygon vertices
void printPolygon(const Polygon* poly) {
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

// Calculate area of a polygon using the shoelace formula
double calculateArea(const Polygon* poly) {
    double area = 0.0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices; // Wrap around to the first vertex
        area += poly->vertices[i].x * poly->vertices[j].y;
        area -= poly->vertices[j].x * poly->vertices[i].y;
    }
    area = fabs(area) / 2.0;
    return area;
}

// Calculate perimeter of the polygon
double calculatePerimeter(const Polygon* poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices;
        double dx = poly->vertices[j].x - poly->vertices[i].x;
        double dy = poly->vertices[j].y - poly->vertices[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

// Check if a point is inside a polygon using ray-casting algorithm
int isPointInsidePolygon(const Polygon* poly, Point p) {
    int count = 0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices;
        
        // Check if the point is on the edge
        if ((poly->vertices[i].y > p.y) != (poly->vertices[j].y > p.y) &&
            (p.x < (poly->vertices[j].x - poly->vertices[i].x) * (p.y - poly->vertices[i].y) /
             (poly->vertices[j].y - poly->vertices[i].y) + poly->vertices[i].x)) {
            count++;
        }
    }
    return count % 2; // Odd count means inside
}

// Translate the polygon by (tx, ty)
void translatePolygon(Polygon* poly, double tx, double ty) {
    for (int i = 0; i < poly->num_vertices; i++) {
        poly->vertices[i].x += tx;
        poly->vertices[i].y += ty;
    }
}

// Rotate the polygon around the origin
void rotatePolygon(Polygon* poly, double angleDegrees) {
    double angleRadians = angleDegrees * PI / 180.0;
    double cosTheta = cos(angleRadians);
    double sinTheta = sin(angleRadians);
    
    for (int i = 0; i < poly->num_vertices; i++) {
        double xOld = poly->vertices[i].x;
        double yOld = poly->vertices[i].y;
        
        poly->vertices[i].x = xOld * cosTheta - yOld * sinTheta;
        poly->vertices[i].y = xOld * sinTheta + yOld * cosTheta;
    }
}