//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 32

typedef struct fib_sequence {
    unsigned int length;
    unsigned int *data;
} fib_sequence;

void fibonacci(unsigned int *fib, unsigned int n);
void print_sequence(const fib_sequence *seq);

int main() {
    unsigned int n, *fib = NULL;
    fib_sequence seq;

    printf("Enter the number of Fibonacci numbers to display: ");
    if (scanf("%u", &n) != 1 || n > MAX_INPUT) {
        fprintf(stderr, "Invalid input. Please enter a positive integer below %u.\n", MAX_INPUT);
        return 1;
    }

    seq.length = n;
    fibonacci(fib, n);

    seq.data = malloc(sizeof(unsigned int) * seq.length);
    if (!seq.data) {
        fprintf(stderr, "Failed to allocate memory for sequence.\n");
        free(fib);
        return 1;
    }

    fibonacci(seq.data, n);
    print_sequence(&seq);

    free(seq.data);
    free(fib);

    return 0;
}

void fibonacci(unsigned int *fib, unsigned int n) {
    unsigned int i, a = 0, b = 1;

    for (i = 0; i < n; i++) {
        fib[i] = a;
        a = b;
        b += a;
    }
}

void print_sequence(const fib_sequence *seq) {
    unsigned int i;

    printf("Fibonacci sequence of length %u:\n", seq->length);
    for (i = 0; i < seq->length; i++) {
        printf("%u ", seq->data[i]);
    }
    putchar('\n');
}