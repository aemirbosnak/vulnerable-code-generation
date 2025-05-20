//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point **points;
    int num_points;
} Polygon;

void generate_points(Polygon *polygon) {
    srand(time(NULL));
    for (int i = 0; i < polygon->num_points; i++) {
        polygon->points[i] = (Point *) malloc(sizeof(Point));
        polygon->points[i]->row = rand() % MAX_SIZE;
        polygon->points[i]->col = rand() % MAX_SIZE;
    }
}

int is_convex(Polygon *polygon) {
    int sum = 0;
    for (int i = 0; i < polygon->num_points; i++) {
        Point *p1 = polygon->points[i];
        Point *p2 = polygon->points[(i + 1) % polygon->num_points];
        Point *p3 = polygon->points[(i + 2) % polygon->num_points];
        sum += (p1->row * p2->col + p2->row * p3->col + p3->row * p1->col) -
              (p1->col * p2->row + p2->col * p3->row + p3->col * p1->row);
    }
    return sum == 0;
}

void print_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->num_points; i++) {
        printf("(%d, %d)\n", polygon->points[i]->row, polygon->points[i]->col);
    }
}

int main() {
    Polygon polygon;
    polygon.num_points = 5;
    polygon.points = (Point **) malloc(polygon.num_points * sizeof(Point *));
    generate_points(&polygon);
    if (is_convex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is not convex.\n");
    }
    print_polygon(&polygon);
    return 0;
}