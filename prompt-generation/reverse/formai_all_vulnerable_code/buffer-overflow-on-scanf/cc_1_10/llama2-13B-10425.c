//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M 10 // number of math operations to perform
#define N 100 // size of the array

int main() {
    int arr[N];
    int i, j, k;
    int sum = 0;
    int product = 1;
    int max = -1;
    int min = 100;

    // read the array elements from the user
    for (i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // perform the math operations
    for (i = 0; i < M; i++) {
        switch (i) {
            case 0: // addition
                for (j = 0; j < N; j++) {
                    sum += arr[j];
                }
                break;
            case 1: // subtraction
                for (j = 0; j < N; j++) {
                    sum -= arr[j];
                }
                break;
            case 2: // multiplication
                for (j = 0; j < N; j++) {
                    product *= arr[j];
                }
                break;
            case 3: // division
                for (j = 0; j < N; j++) {
                    product /= arr[j];
                }
                break;
            case 4: // modulus
                for (j = 0; j < N; j++) {
                    product = fmod(product, arr[j]);
                }
                break;
            case 5: // exponentiation
                for (j = 0; j < N; j++) {
                    product = pow(product, arr[j]);
                }
                break;
            case 6: // square root
                for (j = 0; j < N; j++) {
                    product = sqrt(product);
                }
                break;
            case 7: // greatest common divisor
                for (j = 0; j < N; j++) {
                    gcd(product, arr[j]);
                }
                break;
            case 8: // least common multiple
                for (j = 0; j < N; j++) {
                    lcm(product, arr[j]);
                }
                break;
        }
    }

    // print the results
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}

// function to calculate gcd
int gcd(int a, int b) {
    while (b != 0) {
        a = b;
        b = a % b;
    }
    return a;
}

// function to calculate lcm
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}