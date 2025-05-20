//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

void normalize(Point *point) {
    double len = sqrt(point->x * point->x + point->y * point->y);
    point->x /= len;
    point->y /= len;
}

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x, dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void print_point(Point p) {
    printf("(%lf, %lf)", p.x, p.y);
}

int main() {
    Point points[MAX_POINTS];
    int num_points = 0;

    while (1) {
        printf("Enter x and y coordinates (q to quit): ");
        scanf("%lf %lf", &points[num_points].x, &points[num_points].y);
        if (points[num_points].x == 0 && points[num_points].y == 0) break;
        num_points++;
    }

    if (num_points < 3) {
        printf("Need at least 3 points to calculate centroid.\n");
        return 1;
    }

    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < num_points; i++) {
        sum_x += points[i].x;
        sum_y += points[i].y;
    }

    double avg_x = sum_x / num_points, avg_y = sum_y / num_points;

    printf("\nCentroid:\n");
    print_point((Point){avg_x, avg_y});

    Point centroid = (Point){avg_x, avg_y};
    double total_distance = 0;

    for (int i = 0; i < num_points; i++) {
        double dist = distance(points[i], centroid);
        total_distance += dist * dist;
    }

    double avg_distance = sqrt(total_distance / num_points);

    printf("\nAverage distance from centroid: %lf\n", avg_distance);

    return 0;
}