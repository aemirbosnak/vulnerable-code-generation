//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
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
    int count;
} PointList;

void add_point(PointList *list, double x, double y) {
    if (list->count < MAX_POINTS) {
        list->points[list->count].x = x;
        list->points[list->count].y = y;
        list->count++;
    } else {
        printf("Point list is full!\n");
    }
}

void print_points(const PointList *list) {
    printf("Points:\n");
    for (int i = 0; i < list->count; i++) {
        printf("(%f, %f)\n", list->points[i].x, list->points[i].y);
    }
}

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perimeter(const PointList *list) {
    double total = 0.0;
    for (int i = 0; i < list->count; i++) {
        total += distance(list->points[i], list->points[(i + 1) % list->count]);
    }
    return total;
}

double area(const PointList *list) {
    double sum = 0.0;
    for (int i = 0; i < list->count; i++) {
        sum += (list->points[i].x * list->points[(i + 1) % list->count].y)
             - (list->points[(i + 1) % list->count].x * list->points[i].y);
    }
    return fabs(sum) / 2.0;
}

int is_point_in_polygon(PointList *polygon, Point p) {
    int counter = 0;
    for (int i = 0; i < polygon->count; i++) {
        Point a = polygon->points[i];
        Point b = polygon->points[(i + 1) % polygon->count];

        if (((a.y <= p.y && p.y < b.y) || (b.y <= p.y && p.y < a.y)) &&
            (p.x < (b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x)) {
            counter++;
        }
    }
    return counter % 2;
}

void input_points(PointList *list) {
    double x, y;
    printf("Enter the points (x y), end with -1 -1:\n");
    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == -1 && y == -1) break;
        add_point(list, x, y);
    }
}

int main() {
    PointList polygon;
    polygon.count = 0;

    input_points(&polygon);
    
    print_points(&polygon);
    
    printf("Perimeter: %lf\n", perimeter(&polygon));
    printf("Area: %lf\n", area(&polygon));

    Point test_point;
    printf("Enter a point to check if it's inside the polygon: ");
    scanf("%lf %lf", &test_point.x, &test_point.y);
    
    if (is_point_in_polygon(&polygon, test_point)) {
        printf("The point (%f, %f) is inside the polygon.\n", test_point.x, test_point.y);
    } else {
        printf("The point (%f, %f) is outside the polygon.\n", test_point.x, test_point.y);
    }

    return 0;
}