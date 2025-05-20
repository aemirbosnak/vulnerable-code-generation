//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 45
#define MAX_FIB 1000

int fib[MAX_FIB];
int top = 0;
int x_offset = (WIDTH - 10) / 2;
int y_offset = (HEIGHT - 6) / 2;

void init_fib() {
    fib[0] = 0;
    fib[1] = 1;
    top = 2;
}

void generate_fib() {
    int i;
    for (i = top - 1; i > 0; i--) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    top++;
}

void draw_fib() {
    int i;
    system("clear");
    printf("+%c", '-', WIDTH);
    printf("\n");
    for (i = 0; i < top; i++) {
        int x = x_offset + i * (WIDTH - 20) / (top - 1);
        int y = y_offset - fib[i] * (HEIGHT - 6) / MAX_FIB;
        printf("%4d ", fib[i]);
        if (y >= 0 && y < HEIGHT - 6) {
            printf("\033[6;%dH*\033[0m", y + 6);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    init_fib();
    while (1) {
        generate_fib();
        draw_fib();
        usleep(100000);
    }
    return 0;
}