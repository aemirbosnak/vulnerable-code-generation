//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find the sum of the digits of a number
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is a Kaprekar number
bool isKaprekar(int n) {
    if (n <= 1) {
        return true;
    }
    int sqr = n * n;
    int len = 0;
    int temp = sqr;
    while (temp > 0) {
        len++;
        temp /= 10;
    }
    int left = sqr / pow(10, len / 2);
    int right = sqr % (int)pow(10, len / 2);
    return left + right == n;
}

// Main function
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }
    printf("The sum of the digits of %d is %d.\n", n, sumOfDigits(n));
    if (isKaprekar(n)) {
        printf("%d is a Kaprekar number.\n", n);
    } else {
        printf("%d is not a Kaprekar number.\n", n);
    }
    return 0;
}