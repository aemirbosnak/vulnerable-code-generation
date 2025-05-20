//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000 // Maximum number to check

int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not a prime number
    }

    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }

    return 1; // Prime number
}

int main() {
    int count = 0;
    int num;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    int primes[num];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random numbers between 2 and MAX
    int i;
    for (i = 0; i < num; i++) {
        int randomNum = rand() % MAX + 2; // Start from 2

        while (!isPrime(randomNum)) { // Keep generating until a prime number is found
            randomNum = rand() % MAX + 2; // Start from 2
        }

        primes[i] = randomNum;
        printf("%d is a prime number.\n", randomNum);
        count++;
    }

    if (count == num) {
        printf("%d prime numbers generated successfully.\n", num);
    } else {
        printf("%d prime numbers could not be generated.\n", num - count);
    }

    return 0;
}