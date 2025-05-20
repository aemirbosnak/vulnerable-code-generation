//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000000

bool isPrime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void sieveOfEratosthenes(int n) {
    int i, j;
    bool prime[MAX + 1];
    for (i = 0; i <= n; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (i = 0; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);
    int count = 0;
    while (count < n) {
        int prime = 2;
        while (!isPrime(prime)) {
            prime++;
        }
        printf("%d ", prime);
        count++;
    }
    return 0;
}