//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SQUARE_SIZE 100
#define POINTS_COUNT 100

typedef struct {
    double x, y;
} Point;

double euclidean_distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void print_point(Point p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

Point random_point() {
    Point p;
    p.x = (double) rand() / RAND_MAX * SQUARE_SIZE;
    p.y = (double) rand() / RAND_MAX * SQUARE_SIZE;
    return p;
}

int main() {
    srand(time(NULL));
    Point points[POINTS_COUNT];
    double shortest_distance = INFINITY;
    Point point1, point2;

    for (int i = 0; i < POINTS_COUNT; ++i) {
        points[i] = random_point();
        for (int j = i + 1; j < POINTS_COUNT; ++j) {
            Point current_point = points[j];
            double distance = euclidean_distance(points[i], current_point);
            if (distance < shortest_distance) {
                shortest_distance = distance;
                point1 = points[i];
                point2 = current_point;
            }
        }
    }

    printf("The shortest distance between points is: %.2f\n", shortest_distance);
    printf("Coordinates of the points are: ");
    print_point(point1);
    printf(" and ");
    print_point(point2);
    printf(".\n");

    return 0;
}