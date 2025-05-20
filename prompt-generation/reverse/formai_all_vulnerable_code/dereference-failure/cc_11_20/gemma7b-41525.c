//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Point {
    int x;
    int y;
} Point;

int main() {
    Point points[MAX];
    int n, i, j, k, l, area, perimeter;
    char **grid;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    points[0].x = points[0].y = 0;
    for (i = 1; i < n; i++) {
        printf("Enter the coordinates of point %d: ", i);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    grid = (char *)malloc(n * MAX);
    for (i = 0; i < n; i++) {
        grid[i] = malloc(MAX);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                grid[i][j] = 1;
            }
        }
    }

    area = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                l = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
                area += l;
            }
        }
    }

    perimeter = 0;
    for (i = 0; i < n; i++) {
        perimeter += abs(points[i].x - points[0].x) + abs(points[i].y - points[0].y);
    }

    printf("The area of the polygon is: %d", area);
    printf("\nThe perimeter of the polygon is: %d", perimeter);

    return 0;
}