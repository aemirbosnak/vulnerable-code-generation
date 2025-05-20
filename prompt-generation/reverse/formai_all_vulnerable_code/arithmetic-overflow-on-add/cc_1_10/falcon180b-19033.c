//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

void drawLine(Point start, Point end) {
    int x1, y1, x2, y2, steps;
    x1 = start.x;
    y1 = start.y;
    x2 = end.x;
    y2 = end.y;
    steps = abs(x2 - x1);

    if (y1 < y2) {
        y1 += steps;
        y2 -= steps;
    } else {
        y1 -= steps;
        y2 += steps;
    }

    while (x1 <= x2) {
        printf("*");
        x1++;
    }

    printf("\n");
}

int main() {
    int x1, y1, x2, y2, steps, i;
    Point p1, p2;

    printf("Enter the coordinates of the first point:\n");
    scanf("%d %d", &x1, &y1);
    p1.x = x1;
    p1.y = y1;

    printf("Enter the coordinates of the second point:\n");
    scanf("%d %d", &x2, &y2);
    p2.x = x2;
    p2.y = y2;

    if (x1 == x2) {
        printf("Cannot draw a line with the same x coordinates.\n");
        return 0;
    }

    steps = abs(x2 - x1);

    if (y1 < y2) {
        y1 += steps;
        y2 -= steps;
    } else {
        y1 -= steps;
        y2 += steps;
    }

    for (i = 0; i <= steps; i++) {
        drawLine(p1, p2);
        p1.x += 1;
        p2.x -= 1;
    }

    return 0;
}