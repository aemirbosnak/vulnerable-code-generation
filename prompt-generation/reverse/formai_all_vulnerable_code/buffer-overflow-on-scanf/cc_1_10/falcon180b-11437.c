//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_FIB_NUM 100
#define MAX_COLORS 6

typedef struct {
    int num;
    int color;
} FibonacciPair;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacciPairs(int num, FibonacciPair* pairs) {
    pairs[0].num = 0;
    pairs[0].color = rand() % MAX_COLORS;

    pairs[1].num = 1;
    pairs[1].color = rand() % MAX_COLORS;

    for (int i = 2; i < num; i++) {
        pairs[i].num = fibonacci(i - 1);
        pairs[i].color = rand() % MAX_COLORS;
    }
}

void printFibonacciPairs(FibonacciPair* pairs, int num) {
    for (int i = 0; i < num; i++) {
        printf("Fibonacci number %d is %d and its color is %d\n", i + 1, pairs[i].num, pairs[i].color);
    }
}

int main(void) {
    int num;
    printf("Enter the number of Fibonacci numbers you want to generate: ");
    scanf("%d", &num);

    if (num <= 0 || num > MAX_FIB_NUM) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_FIB_NUM);
        return 1;
    }

    FibonacciPair pairs[MAX_FIB_NUM];
    generateFibonacciPairs(num, pairs);
    printFibonacciPairs(pairs, num);

    return 0;
}