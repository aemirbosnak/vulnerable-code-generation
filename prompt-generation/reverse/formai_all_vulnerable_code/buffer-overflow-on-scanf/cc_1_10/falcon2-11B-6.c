//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_NUM 1000000

typedef struct {
    int number;
    int index;
    int index2;
    int fib;
} fibonacci;

fibonacci *fibonacci_sequence(int length) {
    fibonacci *sequence = malloc(sizeof(fibonacci) * length);
    if (!sequence) {
        return NULL;
    }
    int i, j, k;
    for (i = 0; i < length; i++) {
        sequence[i].number = 0;
        sequence[i].index = 0;
        sequence[i].index2 = 0;
        sequence[i].fib = 0;
    }
    sequence[0].number = 0;
    sequence[0].index = 1;
    sequence[0].index2 = 0;
    sequence[0].fib = 0;
    sequence[1].number = 1;
    sequence[1].index = 2;
    sequence[1].index2 = 1;
    sequence[1].fib = 1;
    for (i = 2; i < length; i++) {
        sequence[i].number = sequence[i - 1].number + sequence[i - 2].number;
        sequence[i].index = i;
        sequence[i].index2 = i - 1;
        sequence[i].fib = sequence[i - 1].fib + sequence[i - 2].fib;
    }
    return sequence;
}

int main() {
    int length, fib;
    char line[MAX_LENGTH];
    fibonacci *sequence;

    printf("Enter length of the Fibonacci sequence: ");
    scanf("%d", &length);
    if (length < 2 || length > MAX_NUM) {
        printf("Length must be between 2 and %d\n", MAX_NUM);
        return 1;
    }
    sequence = fibonacci_sequence(length);
    if (!sequence) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Fibonacci sequence:\n");
    for (fib = 0; fib < length; fib++) {
        printf("%d: %d %d %d %d\n", fib, sequence[fib].number, sequence[fib].index, sequence[fib].index2, sequence[fib].fib);
    }
    free(sequence);
    return 0;
}