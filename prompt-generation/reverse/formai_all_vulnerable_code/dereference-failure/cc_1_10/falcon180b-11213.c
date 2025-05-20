//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
    int capacity;
} Points;

Points *create_points(int capacity) {
    Points *points = (Points *)malloc(sizeof(Points));
    if (points == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    points->points = (Point *)malloc(capacity * sizeof(Point));
    if (points->points == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    points->size = 0;
    points->capacity = capacity;
    return points;
}

void destroy_points(Points *points) {
    free(points->points);
    free(points);
}

void add_point(Points *points, int x, int y) {
    if (points->size >= points->capacity) {
        printf("Error: Points array is full.\n");
        return;
    }
    points->points[points->size].x = x;
    points->points[points->size].y = y;
    points->size++;
}

int get_point(Points *points, int index) {
    if (index >= points->size) {
        printf("Error: Invalid index.\n");
        return -1;
    }
    return points->points[index].x;
}

void set_point(Points *points, int index, int x, int y) {
    if (index >= points->size) {
        printf("Error: Invalid index.\n");
        return;
    }
    points->points[index].x = x;
    points->points[index].y = y;
}

int distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void sort_points(Points *points) {
    for (int i = 0; i < points->size - 1; i++) {
        for (int j = i + 1; j < points->size; j++) {
            if (distance(get_point(points, i), get_point(points, j), 0, 0) > distance(get_point(points, j), get_point(points, i), 0, 0)) {
                Point temp = points->points[i];
                points->points[i] = points->points[j];
                points->points[j] = temp;
            }
        }
    }
}

int main() {
    int capacity = MAX_SIZE;
    Points *points = create_points(capacity);

    int x, y;
    printf("Enter the coordinates of the points (x, y):\n");
    for (int i = 0; i < capacity; i++) {
        scanf("%d %d", &x, &y);
        add_point(points, x, y);
    }

    printf("Unsorted points:\n");
    for (int i = 0; i < points->size; i++) {
        printf("%d ", get_point(points, i));
    }
    printf("\n");

    sort_points(points);

    printf("Sorted points:\n");
    for (int i = 0; i < points->size; i++) {
        printf("%d ", get_point(points, i));
    }
    printf("\n");

    destroy_points(points);
    return 0;
}