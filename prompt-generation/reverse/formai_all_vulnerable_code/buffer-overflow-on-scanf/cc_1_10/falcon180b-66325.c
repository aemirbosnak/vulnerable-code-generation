//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

void draw_fractal(int n, Point *points) {
    for (int i = 0; i < n; i++) {
        int x = points[i].x;
        int y = points[i].y;
        printf(" ");
        for (int j = 0; j < n; j++) {
            if (i == j) {
                printf("*");
            } else if (x == points[j].x || y == points[j].y) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_fractal(int n, Point *points) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                points[i] = (Point) { i, j };
            } else if (i == n - 1 || j == n - 1) {
                points[i] = (Point) { i, j };
            } else if (rand() % 2 == 0) {
                points[i] = (Point) { i, j };
            } else {
                points[i] = (Point) { i, j };
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the fractal: ");
    scanf("%d", &n);

    Point *points = malloc(n * sizeof(Point));
    generate_fractal(n, points);
    draw_fractal(n, points);

    free(points);
    return 0;
}