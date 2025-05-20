//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the sum of a series
double series_sum(double a, double r, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a * pow(r, i);
    }
    return sum;
}

// Function to calculate the n-th Fibonacci number
double fibonacci(int n) {
    double a = 0;
    double b = 1;
    double c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

// Function to calculate the n-th prime number
int prime(int n) {
    int count = 0;
    int i = 2;
    while (count < n) {
        if (isPrime(i)) {
            count++;
        }
        i++;
    }
    return i - 1;
}

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int choice;
    double a, r, n;
    int num;

    // Menu-driven program
    do {
        printf("Enter your choice:\n");
        printf("1. Calculate series sum\n");
        printf("2. Calculate n-th Fibonacci number\n");
        printf("3. Calculate n-th prime number\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a, r, and n:\n");
                scanf("%lf %lf %d", &a, &r, &n);
                printf("The sum of the series is %.2lf\n", series_sum(a, r, n));
                break;
            case 2:
                printf("Enter n:\n");
                scanf("%d", &num);
                printf("The %d-th Fibonacci number is %.0lf\n", num, fibonacci(num));
                break;
            case 3:
                printf("Enter n:\n");
                scanf("%d", &num);
                printf("The %d-th prime number is %d\n", num, prime(num));
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}