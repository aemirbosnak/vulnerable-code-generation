//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to convert an integer into its base-n representation
int int_to_base_n(int n, int base) {
    if (n == 0) {
        return '0';
    } else if (n < 0) {
        return '-';
    } else if (n == 1) {
        return '1';
    } else {
        char digit;
        int remainder = n % base;
        digit = int_to_base_n(remainder, base);
        n /= base;
        return digit + int_to_base_n(n, base);
    }
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 1;
    } else {
        int product = 1;
        for (int i = 1; i <= n; i++) {
            product *= i;
        }
        return product;
    }
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: Input must be a non-negative integer.\n");
        return 1;
    }

    int base = 10;
    char* result = int_to_base_n(n, base);
    printf("The factorial of %d is %s.\n", n, result);

    return 0;
}