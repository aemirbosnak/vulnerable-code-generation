//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

// Function prototypes
void generate_random_points(Point points[], int n);
void print_points(Point points[], int n);
double calculate_distance(Point a, Point b);
double calculate_area_of_triangle(Point a, Point b, Point c);
double calculate_perimeter_of_triangle(Point a, Point b, Point c);
double calculate_centroid(Point a, Point b, Point c, Point* centroid);
double calculate_area_of_polygon(Point points[], int n);

int main() {
    Point points[MAX_POINTS];
    int n;

    printf("Enter the number of points to generate (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n < 3 || n > MAX_POINTS) {
        printf("Please enter a number between 3 and %d.\n", MAX_POINTS);
        return 1;
    }

    generate_random_points(points, n);
    print_points(points, n);

    // Calculate area of polygon formed by given points
    double area = calculate_area_of_polygon(points, n);
    printf("Area of the polygon: %.2f\n", area);

    // Calculate centroid of the polygon
    Point centroid;
    for (int i = 0; i < n; i += 3) {
        if (i + 2 < n) {
            double area_triangle = calculate_area_of_triangle(points[i], points[i + 1], points[i + 2]);
            calculate_centroid(points[i], points[i + 1], points[i + 2], &centroid);
            printf("Area of Triangle %d-%d-%d: %.2f, Centroid: (%.2f, %.2f)\n", i, i + 1, i + 2, area_triangle, centroid.x, centroid.y);
        }
    }

    return 0;
}

void generate_random_points(Point points[], int n) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        points[i].x = (double)(rand() % 100);
        points[i].y = (double)(rand() % 100);
    }
}

void print_points(Point points[], int n) {
    printf("Generated Points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, points[i].x, points[i].y);
    }
}

double calculate_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double calculate_area_of_triangle(Point a, Point b, Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

double calculate_perimeter_of_triangle(Point a, Point b, Point c) {
    double ab = calculate_distance(a, b);
    double bc = calculate_distance(b, c);
    double ca = calculate_distance(c, a);
    return ab + bc + ca;
}

double calculate_centroid(Point a, Point b, Point c, Point* centroid) {
    centroid->x = (a.x + b.x + c.x) / 3.0;
    centroid->y = (a.y + b.y + c.y) / 3.0;
    return 0; // Return success
}

double calculate_area_of_polygon(Point points[], int n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y) - (points[j].x * points[i].y);
    }
    return fabs(area) / 2.0;
}