//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 25

struct point {
    int x;
    int y;
};

struct point origin;
struct point p1, p2;
int fib[100];
bool drawing;

void init_fibonacci() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void init_points() {
    origin.x = WIDTH / 2;
    origin.y = HEIGHT / 2;
    p1.x = origin.x;
    p1.y = origin.y - 1;
    p2.x = origin.x + 1;
    p2.y = origin.y;
}

void draw_point(struct point p) {
    if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT) {
        printf("#");
    } else {
        printf(" ");
    }
}

void draw_line(struct point p1, struct point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = p1.x;
    float y = p1.y;
    for (int i = 0; i <= steps; i++) {
        draw_point((struct point){ (int)x, (int)y });
        x += x_inc;
        y += y_inc;
    }
}

void draw_fibonacci() {
    for (int i = 0; i < 100; i++) {
        if (i == 0) {
            draw_point(origin);
        } else {
            draw_line(p2, (struct point){ p2.x + fib[i - 1], p2.y - fib[i] });
            p1 = p2;
            p2.x += fib[i - 1];
            p2.y -= fib[i];
        }
    }
}

int main() {
    init_fibonacci();
    init_points();
    draw_fibonacci();
    return 0;
}