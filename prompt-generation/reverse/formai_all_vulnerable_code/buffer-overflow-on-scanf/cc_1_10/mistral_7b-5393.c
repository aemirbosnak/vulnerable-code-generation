//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate next prime number
int nextPrime(int num) {
    int prime;
    do {
        prime = num + 1;
    } while (!isPrime(prime));
    return prime;
}

int main() {
    int num, limit;
    clock_t start, end;

    printf("Enter the number up to which you want prime numbers:\n");
    scanf("%d", &limit);

    printf("First %d prime numbers are:\n", limit);

    start = clock();

    num = 2;
    for (int i = 0; i < limit; i++) {
        printf("%d ", num);
        num = nextPrime(num);
    }

    end = clock();

    printf("\nTotal time taken: %fs\n", (end - start) / CLOCKS_PER_SEC);

    return 0;
}

// Keep exploring the world of coding!
// Stay enthusiastic and keep learning new things!
// Keep Coding and have a great day!