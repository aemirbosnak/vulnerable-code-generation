//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    int dx1, dy1, dx2, dy2, dx3, dy3;
    int minX, maxX, minY, maxY;

    dx1 = x2 - x1;
    dy1 = y2 - y1;
    dx2 = x3 - x2;
    dy2 = y3 - y2;
    dx3 = x1 - x3;
    dy3 = y1 - y3;

    minX = x1;
    maxX = x1;
    minY = y1;
    maxY = y1;

    if (x2 < minX) {
        minX = x2;
    }
    if (x2 > maxX) {
        maxX = x2;
    }
    if (y2 < minY) {
        minY = y2;
    }
    if (y2 > maxY) {
        maxY = y2;
    }

    if (x3 < minX) {
        minX = x3;
    }
    if (x3 > maxX) {
        maxX = x3;
    }
    if (y3 < minY) {
        minY = y3;
    }
    if (y3 > maxY) {
        maxY = y3;
    }

    int x, y;

    for (y = minY; y <= maxY; y++) {
        for (x = minX; x <= maxX; x++) {
            if ((dx1 * (y - y1) + dx2 * (y - y2) + dx3 * (y - y3)) == 0) {
                int color = (x == x1 && y == y1)? 1 : (x == x2 && y == y2)? 2 : 3;
                printf("%d ", color);
            }
        }
        printf("\n");
    }
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates of first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter coordinates of third point: ");
    scanf("%d %d", &x3, &y3);

    draw_triangle(x1, y1, x2, y2, x3, y3);

    return 0;
}