//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[MAX_POINTS];
    int num_points;
} Polygon;

void add_point(Polygon *polygon, double x, double y) {
    if (polygon->num_points < MAX_POINTS) {
        polygon->points[polygon->num_points].x = x;
        polygon->points[polygon->num_points].y = y;
        polygon->num_points++;
    } else {
        printf("Maximum number of points reached!\n");
    }
}

double calculate_area(Polygon *polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->num_points; i++) {
        int next = (i + 1) % polygon->num_points;
        area += (polygon->points[i].x * polygon->points[next].y) -
                (polygon->points[next].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

double calculate_perimeter(Polygon *polygon) {
    double perimeter = 0.0;
    for (int i = 0; i < polygon->num_points; i++) {
        int next = (i + 1) % polygon->num_points;
        double dx = polygon->points[next].x - polygon->points[i].x;
        double dy = polygon->points[next].y - polygon->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void display_polygon(Polygon *polygon) {
    printf("Polygon with %d points:\n", polygon->num_points);
    for (int i = 0; i < polygon->num_points; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

void main_menu() {
    printf("****************************************\n");
    printf("*          Geometric Algorithms        *\n");
    printf("****************************************\n");
    printf("* 1. Add Point                         *\n");
    printf("* 2. Calculate Area                    *\n");
    printf("* 3. Calculate Perimeter               *\n");
    printf("* 4. Display Polygon                   *\n");
    printf("* 5. Exit                              *\n");
    printf("****************************************\n");
}

int main() {
    Polygon polygon;
    polygon.num_points = 0;
    int choice;
    double x, y;

    while (1) {
        main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter point coordinates (x, y): ");
                scanf("%lf %lf", &x, &y);
                add_point(&polygon, x, y);
                break;

            case 2:
                if (polygon.num_points < 3) {
                    printf("At least 3 points are required to calculate area.\n");
                } else {
                    printf("Area of the polygon: %.2f\n", calculate_area(&polygon));
                }
                break;

            case 3:
                if (polygon.num_points < 2) {
                    printf("At least 2 points are required to calculate perimeter.\n");
                } else {
                    printf("Perimeter of the polygon: %.2f\n", calculate_perimeter(&polygon));
                }
                break;

            case 4:
                display_polygon(&polygon);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}