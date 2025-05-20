//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point* points;
    int num_points;
    double perimeter;
} Polygon;

void* calculate_perimeter(void* arg) {
    Polygon* polygon = arg;
    double perimeter = 0;

    for (int i = 0; i < polygon->num_points - 1; i++) {
        Point p1 = polygon->points[i];
        Point p2 = polygon->points[(i + 1) % polygon->num_points];

        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        perimeter += sqrt(dx*dx + dy*dy);
    }

    polygon->perimeter = perimeter;

    return NULL;
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    Point* points = malloc(num_points * sizeof(Point));

    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    Polygon polygon = { points, num_points, 0 };

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, calculate_perimeter, &polygon);

    printf("Perimeter of the polygon: %lf\n", polygon.perimeter);

    return 0;
}