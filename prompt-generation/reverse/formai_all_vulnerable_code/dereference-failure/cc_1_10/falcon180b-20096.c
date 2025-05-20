//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void generate_random_points(Polygon *polygon, int num_points) {
    polygon->points = (Point *)malloc(sizeof(Point) * num_points);
    polygon->num_points = num_points;

    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        polygon->points[i].x = rand() % 1000;
        polygon->points[i].y = rand() % 1000;
    }
}

int is_point_inside_polygon(Point point, Polygon polygon) {
    int num_points = polygon.num_points;
    Point *points = polygon.points;

    int inside = 0;
    for (int i = 0, j = num_points - 1; i < num_points; j = i++) {
        if ((points[i].y >= point.y)!= (points[j].y >= point.y)
            && point.x < (points[j].x - points[i].x) * (point.y - points[i].y) / (points[j].y - points[i].y) + points[i].x)
            inside =!inside;
    }

    return inside;
}

void print_polygon(Polygon polygon) {
    Point *points = polygon.points;
    int num_points = polygon.num_points;

    for (int i = 0; i < num_points; i++) {
        printf("(%d, %d) ", points[i].x, points[i].y);
    }
}

int main() {
    Polygon polygon;
    generate_random_points(&polygon, 10);

    Point point;
    point.x = 500;
    point.y = 500;

    if (is_point_inside_polygon(point, polygon)) {
        printf("Point is inside the polygon.\n");
    } else {
        printf("Point is outside the polygon.\n");
    }

    print_polygon(polygon);

    return 0;
}