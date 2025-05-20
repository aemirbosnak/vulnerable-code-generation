//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

double get_distance(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[MAX_POINTS];
    printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    double total_distance = 0;
    Point current_point = points[0];

    printf("Starting at point (%d, %d)\n", current_point.x, current_point.y);
    for (int i = 1; i < n; i++) {
        double shortest_distance = -1;
        Point closest_point;
        for (int j = i; j < n; j++) {
            double distance = get_distance(current_point, points[j]);
            if (shortest_distance == -1 || distance < shortest_distance) {
                shortest_distance = distance;
                closest_point = points[j];
            }
        }
        printf("Going to point (%d, %d)\n", closest_point.x, closest_point.y);
        total_distance += shortest_distance;
        current_point = closest_point;
    }

    printf("Finished at point (%d, %d)\n", current_point.x, current_point.y);
    printf("Total distance traveled: %.2lf\n", total_distance);
    return 0;
}