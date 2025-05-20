//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define FIB_MAX 10000
#define BUFFER_SIZE 2048

typedef struct {
    int x, y;
    char c;
} Cell;

Cell fib_matrix[HEIGHT][WIDTH];

void fibonacci(int n, int *a, int *b) {
    int temp;
    if (n <= 1) {
        *a = n;
        *b = n;
    } else {
        fibonacci(n - 1, a, b);
        fibonacci(n - 2, b, &temp);
        *a = *a + *b;
        *b = temp;
    }
}

void draw_cell(int x, int y, char c) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    fib_matrix[y][x].c = c;
}

void clear_cell(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    fib_matrix[y][x].c = ' ';
}

void print_matrix() {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", fib_matrix[y][x].c);
        }
        printf("\n");
    }
}

void fibonacci_visualizer(int n) {
    int a = 0, b = 1;
    int i;

    fibonacci(n, &a, &b);

    for (i = 0; i < a + b; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;

        if (i < a) {
            draw_cell(x, y, 'A');
        } else {
            draw_cell(x, y, 'B');
        }
    }
}

int main() {
    int fib_number;
    clock_t start, end;

    printf("Enter the number of Fibonacci sequence elements to generate and visualize: ");
    scanf("%d", &fib_number);

    if (fib_number > FIB_MAX) {
        printf("Error: Number too large\n");
        return 1;
    }

    start = clock();
    fibonacci_visualizer(fib_number);
    end = clock();

    printf("\nFibonacci sequence of %d numbers calculated and visualized.\n", fib_number);
    printf("Elapsed time: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    print_matrix();

    return 0;
}