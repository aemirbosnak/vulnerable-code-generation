//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 100

typedef struct {
    double x;
    double y;
} Point;

Point* create_point(double x, double y);

double calculate_distance(Point* p1, Point* p2);

Point* calculate_closest_pair(int n, Point* points);

int main() {
    int n, i;
    double x, y;
    Point* closest_pair;
    Point* points;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    points = (Point*) malloc (sizeof(Point) * n);

    printf("Enter the coordinates of the points: ");
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        points[i] = *create_point(x, y);
    }

    closest_pair = calculate_closest_pair(n, points);

    printf("Closest pair is (%lf, %lf) and (%lf, %lf)\n", closest_pair[0].x, closest_pair[0].y, closest_pair[1].x, closest_pair[1].y);
    return 0;
}

Point* create_point(double x, double y) {
    Point* point = (Point*) malloc (sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

double calculate_distance(Point* p1, Point* p2) {
    double x = p1->x - p2->x;
    double y = p1->y - p2->y;
    return sqrt(x*x + y*y);
}

Point* calculate_closest_pair(int n, Point* points) {
    int i, j, count = 0;
    double min_distance = INFINITY, distance;
    Point* closest_pair = (Point*) malloc (sizeof(Point) * 2);

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            distance = calculate_distance(&points[i], &points[j]);
            if(distance < min_distance) {
                min_distance = distance;
                closest_pair[0] = points[i];
                closest_pair[1] = points[j];
            }
        }
    }

    return closest_pair;
}