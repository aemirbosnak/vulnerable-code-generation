//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define WIDTH  80
#define HEIGHT 25

typedef struct {
    int x, y;
} point;

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

void draw_fibonacci(int n) {
    int i, j, k, l;
    int x, y;
    int fib_seq[n];
    int max_fib = fib(n - 1);
    float scale = (float)WIDTH / max_fib;
    char screen[HEIGHT][WIDTH + 1];

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
        screen[i][WIDTH] = '\0';
    }

    for (i = 0; i < n; i++) {
        fib_seq[i] = fib(i);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < fib_seq[i] * scale; j++) {
            x = j;
            y = HEIGHT - 1 - (i + 1);
            screen[y][x] = '*';
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        printf("%s\n", screen[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        return EXIT_FAILURE;
    }

    draw_fibonacci(n);

    return EXIT_SUCCESS;
}