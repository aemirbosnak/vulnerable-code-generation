//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define HEIGHT 25
#define WIDTH 51
#define DELAY 10000

void gotoxy(int x, int y) {
    char buf[32];
    sprintf(buf, "\033[%d;%dH", y, x);
    write(STDOUT_FILENO, buf, strlen(buf));
}

void print_char(int x, int y, char c) {
    gotoxy(x, y);
    putchar(c);
}

void print_space(int x, int y) {
    gotoxy(x, y);
    putchar(' ');
}

void draw_fibonacci_spiral(int max) {
    int x = 0, y = 0, a = 0, b = 1;
    int prev_a = a, prev_b = b;

    while (a < max) {
        print_char(x + 0.5, y, '.');
        print_space(x + 1, y);
        print_space(x, y + 1);
        x = y;
        y = x + (y > 0 ? -1 : 1);

        a = b;
        b = a + prev_a;
        prev_a = a;
        prev_b = b;
    }
}

int main() {
    int max;
    clock_t start;

    printf("\033[2J"); // clear screen

    printf("Enter the maximum number of numbers to print in the Fibonacci sequence: ");
    scanf("%d", &max);

    printf("\n");

    printf("Fibonacci Sequence:\n");
    printf("-------------------\n");

    int fib_a = 0, fib_b = 1;
    int i = 0;

    start = clock();

    while (i < max) {
        printf("%d ", fib_a);
        int next_fib = fib_a + fib_b;
        fib_a = fib_b;
        fib_b = next_fib;
        i++;
    }

    printf("\n\n");

    printf("Fibonacci Spiral:\n");
    printf("------------------\n");

    draw_fibonacci_spiral(max);

    printf("\nComputation time: %.2fs\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}