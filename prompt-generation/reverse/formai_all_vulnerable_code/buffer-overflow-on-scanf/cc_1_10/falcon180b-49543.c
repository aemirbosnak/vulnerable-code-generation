//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000 // Maximum number to check for prime

void sieve_of_eratosthenes(int n) {
    int i, j, count = 0;
    int prime[n+1];
    for(i=2; i<=n; i++) {
        prime[i] = i;
    }
    for(i=2; i*i<=n; i++) {
        for(j=i*i; j<=n; j+=i) {
            prime[j] = 0;
        }
    }
    for(i=2; i<=n; i++) {
        if(prime[i] == i) {
            printf("%d ", i);
            count++;
        }
        if(count == 50) {
            break;
        }
    }
}

int main() {
    int i, n, count = 0;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    srand(time(0));
    for(i=2; count<n; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}

int isPrime(int num) {
    int i;
    if(num <= 1) {
        return 0;
    }
    for(i=2; i<=num/2; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}