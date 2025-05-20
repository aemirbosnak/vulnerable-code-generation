//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_ITER 1000

struct Point {
    float x, y;
};

void swap(struct Point* a, struct Point* b) {
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

int is_equal(struct Point a, struct Point b) {
    return a.x == b.x && a.y == b.y;
}

void print_point(struct Point p) {
    printf("(%f, %f)", p.x, p.y);
}

void print_points(struct Point* points, int n) {
    for (int i = 0; i < n; i++) {
        print_point(points[i]);
        printf(" ");
    }
    printf("\n");
}

struct Point find_closest_pair(struct Point* points, int n) {
    struct Point closest = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x - closest.x < 0.001 && points[i].y - closest.y < 0.001) {
            return closest;
        }
    }
    return closest;
}

void sort_points(struct Point* points, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x > points[j].x) {
                swap(&points[i], &points[j]);
            }
        }
    }
}

int main() {
    struct Point points[MAX_POINTS];
    int n = 0;

    while (scanf("%f %f", &points[n].x, &points[n].y) == 2) {
        n++;
    }

    sort_points(points, n);
    struct Point closest = find_closest_pair(points, n);
    print_points(points, n);
    print_point(closest);

    return 0;
}