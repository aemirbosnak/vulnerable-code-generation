//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

void read_points(Point points[], int* num_points) {
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), stdin) && i < MAX_POINTS) {
        sscanf(line, "%lf %lf", &points[i].x, &points[i].y);
        (*num_points)++;
        i++;
    }
}

double distance_between(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Point find_closest_point(Point center, Point points[], int num_points) {
    Point closest;
    double min_distance = INFINITY;

    for (int i = 0; i < num_points; i++) {
        double current_distance = distance_between(center, points[i]);
        if (current_distance < min_distance) {
            closest = points[i];
            min_distance = current_distance;
        }
    }

    return closest;
}

int main() {
    Point center;
    Point points[MAX_POINTS];
    int num_points;

    read_points(points, &num_points);

    if (num_points == 0) {
        printf("No points provided.\n");
        return 1;
    }

    center.x = points[0].x;
    center.y = points[0].y;

    Point closest = find_closest_point(center, points, num_points);

    printf("Closest point to the center (%lf, %lf): (%lf, %lf)\n", center.x, center.y, closest.x, closest.y);

    return 0;
}