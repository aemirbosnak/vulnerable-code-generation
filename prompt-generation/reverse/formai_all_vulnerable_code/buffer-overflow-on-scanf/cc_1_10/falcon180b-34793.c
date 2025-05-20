//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the permutation of a given number
long long permutation(int n, int r) {
    long long result = factorial(n);
    for (int i = 1; i <= r; i++) {
        result /= i;
    }
    return result;
}

// Function to calculate the combination of a given number
long long combination(int n, int r) {
    long long result = factorial(n);
    for (int i = 1; i <= r; i++) {
        result /= i;
    }
    for (int i = r + 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n, r;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the number of elements to be chosen: ");
    scanf("%d", &r);

    // Calculating permutation and combination of n elements taken r at a time
    long long perm = permutation(n, r);
    long long comb = combination(n, r);

    printf("\nThe permutation of %d elements taken %d at a time is: %lld\n", n, r, perm);
    printf("The combination of %d elements taken %d at a time is: %lld\n", n, r, comb);

    return 0;
}