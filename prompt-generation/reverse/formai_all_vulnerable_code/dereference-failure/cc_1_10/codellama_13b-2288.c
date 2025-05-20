//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 100
#define MAX_DEPTH 10

void fibonacci(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
}

void fibonacci_sequence(int n) {
    int a = 0, b = 1, c = 0;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d\n", c);
    }
}

int main(int argc, char *argv[]) {
    int n;
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid number\n");
        return 1;
    }
    if (n <= MAX_DEPTH) {
        fibonacci_sequence(n);
    } else {
        printf("n should be less than or equal to %d\n", MAX_DEPTH);
    }
    return 0;
}