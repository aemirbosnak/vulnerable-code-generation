//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n);
int nextPrime(int n);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 1) {
        int count = 0;
        int prime = nextPrime(num);
        while (prime <= num) {
            if (isPrime(prime)) {
                count++;
            }
            prime = nextPrime(prime);
        }
        printf("There are %d prime numbers between %d and %d.\n", count, num, prime - 1);
    }
    else {
        printf("Invalid input.\n");
    }

    return 0;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(int n) {
    if (n <= 1) {
        return 2;
    }
    n++;
    while (!isPrime(n)) {
        n++;
    }
    return n;
}