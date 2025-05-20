//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

int main() {
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, k, l, m;
    int temp;
    long long int sum = 0;

    // Exercise 1: Calculate the sum of the first N positive integers
    for (i = 0; i < N; i++) {
        sum += arr[i];
    }
    printf("The sum of the first %d positive integers is: %lld\n", N, sum);

    // Exercise 2: Calculate the product of the first N positive integers
    for (i = 0; i < N; i++) {
        temp = arr[i];
        for (j = 0; j < N; j++) {
            sum *= temp;
        }
    }
    printf("The product of the first %d positive integers is: %lld\n", N, sum);

    // Exercise 3: Calculate the factorial of N
    for (i = 1; i <= N; i++) {
        sum = 1;
        for (j = 1; j <= i; j++) {
            sum *= j;
        }
        printf("The factorial of %d is: %lld\n", i, sum);
    }

    // Exercise 4: Calculate the binomial coefficient C(N, K)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i; j++) {
            sum = 1;
            for (k = 0; k < j; k++) {
                sum *= (i + k);
            }
            printf("C(%d, %d) = %lld\n", N, j, sum);
        }
    }

    return 0;
}