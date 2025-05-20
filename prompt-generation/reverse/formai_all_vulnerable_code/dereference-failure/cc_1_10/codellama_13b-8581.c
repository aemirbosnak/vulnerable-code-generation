//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
// Cyberpunk Geometric Algorithms Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a point
typedef struct {
    float x, y;
} point_t;

// Define the structure for a line
typedef struct {
    point_t start, end;
} line_t;

// Define the structure for a circle
typedef struct {
    point_t center;
    float radius;
} circle_t;

// Define the structure for a rectangle
typedef struct {
    point_t top_left, bottom_right;
} rect_t;

// Define the structure for a polygon
typedef struct {
    int num_vertices;
    point_t* vertices;
} poly_t;

// Function to calculate the distance between two points
float distance(point_t p1, point_t p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Function to calculate the length of a line
float line_length(line_t l) {
    return distance(l.start, l.end);
}

// Function to calculate the area of a circle
float circle_area(circle_t c) {
    return M_PI * c.radius * c.radius;
}

// Function to calculate the area of a rectangle
float rect_area(rect_t r) {
    return (r.bottom_right.x - r.top_left.x) * (r.bottom_right.y - r.top_left.y);
}

// Function to calculate the area of a polygon
float poly_area(poly_t p) {
    float area = 0.0;
    for (int i = 0; i < p.num_vertices; i++) {
        area += (p.vertices[i].x * p.vertices[i + 1].y - p.vertices[i + 1].x * p.vertices[i].y) / 2.0;
    }
    return area;
}

int main() {
    // Declare variables for the shapes
    point_t p1 = {1.0, 2.0};
    point_t p2 = {3.0, 4.0};
    line_t l = {p1, p2};
    circle_t c = {p1, 2.0};
    rect_t r = {p1, p2};
    poly_t poly = {4, (point_t[]){{1.0, 1.0}, {2.0, 1.0}, {2.0, 2.0}, {1.0, 2.0}}};

    // Calculate the distance between two points
    printf("Distance between (%f, %f) and (%f, %f) is %f\n", p1.x, p1.y, p2.x, p2.y, distance(p1, p2));

    // Calculate the length of a line
    printf("Length of line from (%f, %f) to (%f, %f) is %f\n", l.start.x, l.start.y, l.end.x, l.end.y, line_length(l));

    // Calculate the area of a circle
    printf("Area of circle with center (%f, %f) and radius %f is %f\n", c.center.x, c.center.y, c.radius, circle_area(c));

    // Calculate the area of a rectangle
    printf("Area of rectangle with top left (%f, %f) and bottom right (%f, %f) is %f\n", r.top_left.x, r.top_left.y, r.bottom_right.x, r.bottom_right.y, rect_area(r));

    // Calculate the area of a polygon
    printf("Area of polygon with %d vertices is %f\n", poly.num_vertices, poly_area(poly));

    return 0;
}