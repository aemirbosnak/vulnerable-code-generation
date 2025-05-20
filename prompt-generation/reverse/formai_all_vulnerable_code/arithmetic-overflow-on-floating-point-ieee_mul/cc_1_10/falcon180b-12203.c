//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void generate_random_polygon(Polygon *polygon, int num_points) {
    srand(time(NULL));
    polygon->num_points = num_points;
    polygon->points = (Point *)malloc(num_points * sizeof(Point));

    for (int i = 0; i < num_points; i++) {
        polygon->points[i].x = rand() % 1000;
        polygon->points[i].y = rand() % 1000;
    }
}

int is_point_inside_polygon(Point point, Polygon polygon) {
    int inside = 0;
    for (int i = 0; i < polygon.num_points - 1; i++) {
        Point a = polygon.points[i];
        Point b = polygon.points[i + 1];
        if ((b.y > point.y)!= (a.y > point.y) &&
            point.x < (b.x - a.x) * (point.y - a.y) / (b.y - a.y) + a.x)
            inside =!inside;
    }
    return inside;
}

int main() {
    int num_points;
    printf("Enter the number of points for the polygon: ");
    scanf("%d", &num_points);

    Polygon polygon;
    generate_random_polygon(&polygon, num_points);

    int num_points_inside = 0;
    for (int i = 0; i < 1000; i++) {
        Point point;
        point.x = rand() % 1000;
        point.y = rand() % 1000;

        if (is_point_inside_polygon(point, polygon)) {
            num_points_inside++;
        }
    }

    printf("There are %d points inside the polygon.\n", num_points_inside);

    return 0;
}