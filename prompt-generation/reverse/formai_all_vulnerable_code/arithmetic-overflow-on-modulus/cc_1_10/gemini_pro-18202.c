//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate the LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the sum of the digits of a number
int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to find the product of the digits of a number
int product_of_digits(int n) {
    int product = 1;
    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    printf("LCM of %d and %d is %d\n", a, b, lcm(a, b));

    if (is_prime(a)) {
        printf("%d is a prime number\n", a);
    } else {
        printf("%d is not a prime number\n", a);
    }

    printf("Sum of the digits of %d is %d\n", a, sum_of_digits(a));
    printf("Product of the digits of %d is %d\n", a, product_of_digits(a));

    return 0;
}