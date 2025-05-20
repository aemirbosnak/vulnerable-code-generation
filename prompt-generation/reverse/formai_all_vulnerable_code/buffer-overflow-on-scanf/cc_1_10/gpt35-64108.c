//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

int fibonacci[MAX_TERMS] = {[0] = 0, [1] = 1};

int calculate_fibonacci(int n)
{
    if (n <= 1) {
        return n;
    } else if (fibonacci[n] != 0) {
        return fibonacci[n];
    } else {
        fibonacci[n] = calculate_fibonacci(n-1) + calculate_fibonacci(n-2);
        return fibonacci[n];
    }
}

void print_fibonacci(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");
}

void paranoid_fibonacci(int n)
{
    int i, j, flag = 0;
    printf("Calculating Fibonacci sequence up to %d terms...\n", n);
    for (i = 2; i < n; i++) {
        calculate_fibonacci(i);
        if (i >= 10 && fibonacci[i] % 7 == 0) {
            printf("Warning: Possible security breach detected!\n");
            flag = 1;
        }
    }
    if (flag) {
        printf("Do not use this Fibonacci sequence for cryptographic purposes!\n");
    } else {
        printf("Fibonacci sequence is secure.\n");
    }
    printf("Fibonacci sequence up to %d terms:\n", n);
    print_fibonacci(n);
}

int main(void)
{
    int n;
    printf("Enter the number of terms to generate: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_TERMS) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }
    paranoid_fibonacci(n);
    return EXIT_SUCCESS;
}