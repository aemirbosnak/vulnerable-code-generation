//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers
void generatePrimes(int n) {
    int i,j,count=0;
    int *primes = (int*)malloc(n*sizeof(int));
    int *flags = (int*)malloc(n*sizeof(int));

    // Initialize all flags to 1
    for(i=0;i<n;i++) {
        flags[i] = 1;
    }

    // Generate prime numbers
    for(i=2;count<n;i++) {
        if(flags[i]) {
            primes[count++] = i;
            for(j=i*i;j<n;j+=i) {
                flags[j] = 0;
            }
        }
    }

    // Print prime numbers
    printf("Prime numbers: ");
    for(i=0;i<n;i++) {
        printf("%d ",primes[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Get number of primes to generate
    printf("Enter number of primes to generate: ");
    scanf("%d",&n);

    // Generate prime numbers
    generatePrimes(n);

    return 0;
}