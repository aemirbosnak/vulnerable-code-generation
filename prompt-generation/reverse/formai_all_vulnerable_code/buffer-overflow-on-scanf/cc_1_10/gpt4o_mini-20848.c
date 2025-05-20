//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
    int capacity;
} Polygon;

// Function to create a new polygon
Polygon* create_polygon(int capacity) {
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    polygon->size = 0;
    polygon->capacity = capacity;
    polygon->points = (Point *)malloc(capacity * sizeof(Point));
    return polygon;
}

// Function to add a point to the polygon
void add_point(Polygon *polygon, double x, double y) {
    if (polygon->size >= polygon->capacity) {
        polygon->capacity *= 2;
        polygon->points = (Point *)realloc(polygon->points, polygon->capacity * sizeof(Point));
    }
    polygon->points[polygon->size].x = x;
    polygon->points[polygon->size].y = y;
    polygon->size++;
}

// Function to calculate the area of the polygon using the shoelace formula
double calculate_area(Polygon *polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->size; i++) {
        int j = (i + 1) % polygon->size;
        area += (polygon->points[i].x * polygon->points[j].y) - (polygon->points[j].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

// Function to calculate the perimeter of the polygon
double calculate_perimeter(Polygon *polygon) {
    double perimeter = 0.0;
    for (int i = 0; i < polygon->size; i++) {
        int j = (i + 1) % polygon->size;
        double dx = polygon->points[j].x - polygon->points[i].x;
        double dy = polygon->points[j].y - polygon->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

// Function to free up memory used for the polygon
void free_polygon(Polygon *polygon) {
    free(polygon->points);
    free(polygon);
}

// Function to display the polygon's points
void display_polygon(Polygon *polygon) {
    printf("Polygon Points:\n");
    for (int i = 0; i < polygon->size; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, polygon->points[i].x, polygon->points[i].y);
    }
}

// Function to read polygon points from the user
void input_polygon(Polygon *polygon) {
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &polygon->size);
    
    for (int i = 0; i < polygon->size; i++) {
        printf("Enter coordinates for Point %d (x y): ", i + 1);
        scanf("%lf %lf", &polygon->points[i].x, &polygon->points[i].y);
    }
}

// Main function to execute the program
int main() {
    int capacity = 5;
    Polygon *polygon = create_polygon(capacity);
    
    input_polygon(polygon);
    
    display_polygon(polygon);

    double area = calculate_area(polygon);
    double perimeter = calculate_perimeter(polygon);
    
    printf("Area of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);
    
    free_polygon(polygon);
    return 0;
}