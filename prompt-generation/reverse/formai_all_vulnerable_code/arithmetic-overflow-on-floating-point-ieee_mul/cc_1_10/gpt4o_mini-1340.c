//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int count;
} Polygon;

// Function declarations
void calculate_area(Polygon *poly);
void calculate_perimeter(Polygon *poly);
void rotate_polygon(Polygon *poly, double angle);
void input_polygon(Polygon *poly);
void print_polygon(Polygon *poly);

int main() {
    Polygon poly;
    poly.points = malloc(MAX_POINTS * sizeof(Point));
    poly.count = 0;

    int choice;
    double rotation_angle;

    while (1) {
        printf("\n--- Polygon Operations Menu ---\n");
        printf("1. Input Polygon\n");
        printf("2. Calculate Area\n");
        printf("3. Calculate Perimeter\n");
        printf("4. Rotate Polygon\n");
        printf("5. Print Polygon\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_polygon(&poly);
                break;
            case 2:
                calculate_area(&poly);
                break;
            case 3:
                calculate_perimeter(&poly);
                break;
            case 4:
                printf("Enter rotation angle in degrees: ");
                scanf("%lf", &rotation_angle);
                rotate_polygon(&poly, rotation_angle);
                break;
            case 5:
                print_polygon(&poly);
                break;
            case 6:
                free(poly.points);
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void input_polygon(Polygon *poly) {
    printf("Enter the number of vertices (max %d): ", MAX_POINTS);
    scanf("%d", &poly->count);
    
    if (poly->count > MAX_POINTS) {
        printf("Too many vertices, limiting to %d.\n", MAX_POINTS);
        poly->count = MAX_POINTS;
    }
    
    for (int i = 0; i < poly->count; i++) {
        printf("Enter coordinates of vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &poly->points[i].x, &poly->points[i].y);
    }
}

void calculate_area(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count;
        area += (poly->points[i].x * poly->points[j].y) - (poly->points[j].x * poly->points[i].y);
    }
    area = fabs(area) / 2.0;
    printf("Area of the polygon: %.2f\n", area);
}

void calculate_perimeter(Polygon *poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count;
        double dx = poly->points[j].x - poly->points[i].x;
        double dy = poly->points[j].y - poly->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    printf("Perimeter of the polygon: %.2f\n", perimeter);
}

void rotate_polygon(Polygon *poly, double angle) {
    double radians = angle * (PI / 180.0);
    double cos_angle = cos(radians);
    double sin_angle = sin(radians);
    
    for (int i = 0; i < poly->count; i++) {
        double x_new = poly->points[i].x * cos_angle - poly->points[i].y * sin_angle;
        double y_new = poly->points[i].x * sin_angle + poly->points[i].y * cos_angle;
        poly->points[i].x = x_new;
        poly->points[i].y = y_new;
    }
    printf("Polygon rotated by %.2f degrees.\n", angle);
}

void print_polygon(Polygon *poly) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < poly->count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->points[i].x, poly->points[i].y);
    }
}