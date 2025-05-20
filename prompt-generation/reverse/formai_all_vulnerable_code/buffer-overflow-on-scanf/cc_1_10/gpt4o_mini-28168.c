//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_POINTS];
    int vertex_count;
} Polygon;

void add_point(Polygon *poly, double x, double y) {
    if (poly->vertex_count < MAX_POINTS) {
        poly->vertices[poly->vertex_count].x = x;
        poly->vertices[poly->vertex_count].y = y;
        poly->vertex_count++;
    } else {
        printf("Max vertex limit reached. Can't add more points.\n");
    }
}

double calculate_area(Polygon *poly) {
    double area = 0.0;
    int j = poly->vertex_count - 1; // Last vertex is the previous vertex to the first
    for (int i = 0; i < poly->vertex_count; i++) {
        area += (poly->vertices[j].x + poly->vertices[i].x) * (poly->vertices[j].y - poly->vertices[i].y);
        j = i; // j is previous vertex to i
    }
    return fabs(area) / 2.0;
}

double calculate_perimeter(Polygon *poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->vertex_count; i++) {
        int next = (i + 1) % poly->vertex_count;
        double dx = poly->vertices[next].x - poly->vertices[i].x;
        double dy = poly->vertices[next].y - poly->vertices[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void display_polygon(Polygon *poly) {
    printf("Polygon with %d vertices:\n", poly->vertex_count);
    for (int i = 0; i < poly->vertex_count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

void draw_polygon(Polygon *poly) {
    // Basic ASCII representation; just for a visual aid
    printf("\nDrawing your polygon:\n");
    for (int i = 0; i < poly->vertex_count; i++) {
        printf("*");
        for (int j = 0; j < 5; j++) printf(" "); // Space for separation
    }
    printf("\n");
}

int main() {
    Polygon poly;
    poly.vertex_count = 0;

    printf("Let's create a polygon!\n");
    printf("Enter the number of vertices (Max %d): ", MAX_POINTS);
    int num_vertices;
    scanf("%d", &num_vertices);

    if (num_vertices < 3 || num_vertices > MAX_POINTS) {
        printf("Invalid number of vertices. Please input between 3 and %d.\n", MAX_POINTS);
        return 1;
    }

    for (int i = 0; i < num_vertices; i++) {
        double x, y;
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        add_point(&poly, x, y);
    }

    display_polygon(&poly);

    double area = calculate_area(&poly);
    double perimeter = calculate_perimeter(&poly);

    printf("\nArea of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);

    draw_polygon(&poly);

    printf("Thank you for creating a polygon!\n");
    return 0;
}