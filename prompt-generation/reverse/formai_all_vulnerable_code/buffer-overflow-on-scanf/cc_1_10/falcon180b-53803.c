//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000
#define MAX_WIDTH 80

typedef struct {
    int num;
    int width;
} fib_t;

// Function to calculate the width of a number
int get_width(int num) {
    int width = 1;
    while (num / 10 > 0) {
        num /= 10;
        width++;
    }
    return width;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    int prev_prev = 0, prev = 1, next = 0;
    int i;
    for (i = 2; i <= n; i++) {
        next = prev + prev_prev;
        prev_prev = prev;
        prev = next;
    }
    return prev;
}

// Function to print a Fibonacci number with the given width
void print_fibonacci(fib_t *fib, int n) {
    int i, j;
    int num = fib->num;
    int width = fib->width;
    for (i = 0; i < MAX_WIDTH; i++) {
        if (i < width) {
            printf(" ");
        } else if (i == width) {
            printf("%d", num);
        } else {
            printf("*");
        }
    }
    printf("\n");
}

// Function to generate a Fibonacci sequence with the given width
void generate_fibonacci(fib_t *fib, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        fib->num = fibonacci(i);
        fib->width = get_width(fib->num);
        for (j = 0; j < MAX_NUM && fib->num < MAX_NUM; j++) {
            print_fibonacci(fib, j);
        }
    }
}

int main() {
    fib_t fib;
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    generate_fibonacci(&fib, n);

    return 0;
}