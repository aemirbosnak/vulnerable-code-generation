//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#define MAX_SEQUENCE 101
#define FIB_MIN 0
#define FIB_MAX ULONG_MAX

void fibonacci(unsigned long long *arr, int num);
void check_input(int num);
void print_sequence(unsigned long long *arr, int num);

int main(int argc, char *argv[]) {
    int num;

    if (argc > 2 || argc < 2) {
        fprintf(stderr, "Usage: %s [number of fibonacci numbers to generate]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    check_input(sscanf(argv[1], "%d", &num) > 0 ? atoi(argv[1]) : -1);

    unsigned long long fib_seq[MAX_SEQUENCE];
    fibonacci(fib_seq, num);

    print_sequence(fib_seq, num);

    return EXIT_SUCCESS;
}

void check_input(int num) {
    if (num <= 0) {
        fprintf(stderr, "Error: Invalid input - Number of Fibonacci numbers must be positive.\n");
        exit(EXIT_FAILURE);
    }
}

void fibonacci(unsigned long long *arr, int num) {
    check_input(num);

    arr[0] = FIB_MIN;
    arr[1] = FIB_MIN;

    for (int i = 2; i < num; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        if (arr[i] > FIB_MAX) {
            fprintf(stderr, "Error: Overflow occurred during Fibonacci sequence calculation.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void print_sequence(unsigned long long *arr, int num) {
    printf("Fibonacci sequence of length %d:\n", num);

    for (int i = 0; i < num; i++) {
        printf("%llu ", arr[i]);
    }

    printf("\n");
}