//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_N 1000

typedef struct {
    int n;
    int x;
    int y;
} point;

int main() {
    int i, j;
    int n;
    int x, y;
    int dx, dy;
    int count;
    int r, g, b;
    point points[MAX_N];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Calculate the Fibonacci sequence
    points[0].n = 0;
    points[0].x = WIDTH / 2;
    points[0].y = HEIGHT / 2;
    points[1].n = 1;
    points[1].x = WIDTH / 2;
    points[1].y = HEIGHT / 2;
    for (i = 2; i < n; i++) {
        points[i].n = points[i - 1].n + points[i - 2].n;
        points[i].x = (points[i - 1].x + points[i - 2].x) / 2;
        points[i].y = (points[i - 1].y + points[i - 2].y) / 2;
    }

    // Draw the Fibonacci sequence
    for (i = 0; i < n; i++) {
        x = points[i].x;
        y = points[i].y;
        count = points[i].n;
        r = (count * 255) / MAX_N;
        g = (255 - count * 255) / MAX_N;
        b = 0;
        for (j = 0; j < count; j++) {
            dx = rand() % 10 - 5;
            dy = rand() % 10 - 5;
            printf("\033[%d;%dH\033[38;2;%d;%d;%dm*\033[0m", y + dy, x + dx, r, g, b);
        }
    }

    return 0;
}