//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the sum of the first n even numbers
double sum_of_even_numbers(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 2 * i;
    }
    return sum;
}

// Function to calculate the sum of the first n odd numbers
double sum_of_odd_numbers(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 2 * i - 1;
    }
    return sum;
}

// Function to calculate the sum of the first n prime numbers
double sum_of_prime_numbers(int n) {
    double sum = 0;
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }
    return sum;
}

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate the sum of the first n even numbers
    double sum_even = sum_of_even_numbers(n);
    printf("The sum of the first %d even numbers is: %.2f\n", n, sum_even);

    // Calculate the sum of the first n odd numbers
    double sum_odd = sum_of_odd_numbers(n);
    printf("The sum of the first %d odd numbers is: %.2f\n", n, sum_odd);

    // Calculate the sum of the first n prime numbers
    double sum_prime = sum_of_prime_numbers(n);
    printf("The sum of the first %d prime numbers is: %.2f\n", n, sum_prime);

    return 0;
}