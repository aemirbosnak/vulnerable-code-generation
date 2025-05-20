//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SEQUENCE_LENGTH 1000
#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point p;
    int value;
} cell;

cell fib_matrix[SCREEN_WIDTH][SCREEN_HEIGHT];

void print_matrix() {
    int i, j;
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            printf("%2d ", fib_matrix[j][i].value);
        }
        printf("\n");
    }
}

void fibonacci(int n, int a, int b) {
    if (n <= 0) {
        fib_matrix[SCREEN_WIDTH / 2][SCREEN_HEIGHT / 2].value = 0;
        return;
    }

    if (n == 1) {
        fib_matrix[SCREEN_WIDTH / 2][SCREEN_HEIGHT / 2].value = a;
        return;
    }

    fibonacci(n - 1, a, b);
    fib_matrix[SCREEN_WIDTH / 2 + (int)floor(sqrt(5.0) * 0.5 * (n - 1) / 2.0)][SCREEN_HEIGHT / 2 + (int)floor((sqrt(5.0) - 1.0) * 0.5 * (n - 1) / 2.0)].value = a + b;
    fib_matrix[SCREEN_WIDTH / 2 + (int)floor(sqrt(5.0) * 0.5 * n / 2.0)][SCREEN_HEIGHT / 2 + (int)floor((sqrt(5.0) - 1.0) * 0.5 * (n - 1) / 2.0)].value = a + b;
    fibonacci(n - 1, b, a + b);
}

int main() {
    int sequence_length;
    clock_t start, end;

    printf("Enter the length of the Fibonacci sequence to generate: ");
    scanf("%d", &sequence_length);

    if (sequence_length > MAX_SEQUENCE_LENGTH) {
        printf("Error: Sequence length too large.\n");
        return 1;
    }

    start = clock();
    fibonacci(sequence_length, 0, 1);
    end = clock();

    printf("Fibonacci sequence of length %d generated in %.6f seconds.\n", sequence_length, (double)(end - start) / CLOCKS_PER_SEC);
    print_matrix();

    return 0;
}