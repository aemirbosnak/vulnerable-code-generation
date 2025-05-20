//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define WIDTH 61
#define HEIGHT 13
#define DELAY 100000
#define BASE 10
#define FMT "%%%ds"

void fib(unsigned int n, unsigned long long *a, unsigned long long *b) {
    unsigned long long t;
    if (n < 2) {
        *a = n;
        *b = 0;
        return;
    }
    fib(n - 1, a, b);
    t = *a + *b;
    *a = *b;
    *b = t;
}

void print_asterisks(unsigned int n) {
    unsigned long long a = 0, b = 1;
    unsigned int i;

    fib(n, &a, &b);

    for (i = 0; i <= n; i++) {
        printf(FMT, "*", WIDTH);
        usleep(DELAY);
        write(STDOUT_FILENO, "\r\r\r\r\r\r\r\r", 8);
        printf(FMT, "*", WIDTH * (i > 0 ? a / BASE : 1));
        usleep(DELAY);
        a = b;
        b = a + b;
    }

    printf("\n");
}

int main() {
    unsigned int n;

    printf("Enter the number of asterisks to print: ");
    scanf("%d", &n);

    if (n > UCHAR_MAX / WIDTH) {
        printf("Error: Number of asterisks too large.\n");
        exit(EXIT_FAILURE);
    }

    print_asterisks(n);

    return EXIT_SUCCESS;
}