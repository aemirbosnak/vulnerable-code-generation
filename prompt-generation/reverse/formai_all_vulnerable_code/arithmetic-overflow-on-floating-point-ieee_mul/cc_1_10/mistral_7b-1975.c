//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 41
#define HEIGHT 11

typedef struct {
    double x, y;
} point_t;

void plot(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    putchar('\033[48;5;202m');
    putchar('*');
    putchar('\033[0m');
}

void draw_line(point_t p1, point_t p2) {
    double dx = fabs(p2.x - p1.x), dy = fabs(p2.y - p1.y);
    double step_x = (p2.x < p1.x) ? -1 : 1, step_y = (p2.y < p1.y) ? -1 : 1;

    double error = dx > dy ? dx / 2.0 : dy / 2.0;

    while ((p1.x != p2.x || p1.y != p2.y)) {
        plot((int)p1.x, (int)p1.y);
        p1.x += step_x;
        p1.y += step_y;
        error -= (dx > dy ? dy : -dy);
    }

    plot((int)p2.x, (int)p2.y);
}

int main() {
    point_t p1 = {5.0, 5.0}, p2 = {10.0, 15.0};

    double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("The distance between (%lf, %lf) and (%lf, %lf) is %lf.\n", p1.x, p1.y, p2.x, p2.y, distance);

    system("clear"); // or cls on Windows

    draw_line(p1, p2);

    return 0;
}