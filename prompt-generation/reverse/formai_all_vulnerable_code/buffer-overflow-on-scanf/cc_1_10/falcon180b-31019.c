//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to calculate factorial of a number
long long int factorial(int n) {
    long long int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if a number is prime or not
int isPrime(int n) {
    int i, flag = 0;
    for(i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0 && n > 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to find the sum of all prime numbers between 1 and n
int sumOfPrimes(int n) {
    int i, sum = 0;
    for(i=2; i<=n; i++) {
        if(isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

// Function to find the product of all prime numbers between 1 and n
long long int productOfPrimes(int n) {
    int i, product = 1;
    for(i=2; i<=n; i++) {
        if(isPrime(i)) {
            product *= i;
        }
    }
    return product;
}

int main() {
    int n, choice;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("\n");
    printf("1. Sum of all prime numbers between 1 and %d\n", n);
    printf("2. Product of all prime numbers between 1 and %d\n", n);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nSum of all prime numbers between 1 and %d: %d\n", n, sumOfPrimes(n));
            break;
        case 2:
            printf("\nProduct of all prime numbers between 1 and %d: %lld\n", n, productOfPrimes(n));
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    return 0;
}