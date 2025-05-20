//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of set bits in a given integer
int count_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

int main() {
    int n, i, j;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input number is a power of two
    if ((n & (n - 1)) == 0) {
        printf("%d is a power of two.\n", n);
    } else {
        printf("%d is not a power of two.\n", n);
    }

    // Check if the input number is a palindrome
    int rev = 0, temp = n;
    while (temp > 0) {
        int rem = temp % 10;
        rev = (rev * 10) + rem;
        temp /= 10;
    }
    if (n == rev) {
        printf("%d is a palindrome.\n", n);
    } else {
        printf("%d is not a palindrome.\n", n);
    }

    // Check if the input number is a strong number
    int sum = 0;
    int cube = n;
    while (cube > 0) {
        int digit = cube % 10;
        sum += factorial(digit);
        cube /= 10;
    }
    if (sum == n) {
        printf("%d is a strong number.\n", n);
    } else {
        printf("%d is not a strong number.\n", n);
    }

    return 0;
}

// Function to calculate the factorial of a given number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}