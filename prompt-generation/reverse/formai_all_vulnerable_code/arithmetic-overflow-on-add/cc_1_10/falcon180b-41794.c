//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *array;
    int size;
} Sieve;

// Function to generate a prime number
int generate_prime(Sieve *sieve) {
    int i, j, count = 0;
    while (count < sieve->size) {
        i = rand() % sieve->size;
        if (sieve->array[i] == 1) {
            count++;
        }
    }
    return i;
}

// Function to initialize the sieve array
void initialize_sieve(Sieve *sieve) {
    int i;
    sieve->array = (int *)malloc(sieve->size * sizeof(int));
    for (i = 0; i < sieve->size; i++) {
        sieve->array[i] = 1;
    }
}

// Function to mark non-prime numbers in the sieve array
void mark_non_primes(Sieve *sieve, int prime) {
    int i;
    for (i = prime * prime; i < sieve->size; i += prime) {
        sieve->array[i] = 0;
    }
}

// Function to generate a sieve of Eratosthenes
Sieve *generate_sieve(int size) {
    Sieve *sieve = (Sieve *)malloc(sizeof(Sieve));
    sieve->array = NULL;
    sieve->size = size;
    sieve->array = (int *)malloc(sieve->size * sizeof(int));
    initialize_sieve(sieve);
    int i, j;
    for (i = 2; i <= sieve->size / 2; i++) {
        if (sieve->array[i] == 1) {
            for (j = i * i; j < sieve->size; j += i) {
                sieve->array[j] = 0;
            }
        }
    }
    return sieve;
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the sieve: ");
    scanf("%d", &size);
    Sieve *sieve = generate_sieve(size);
    int count = 0;
    int prime;
    while (count < 10) {
        prime = generate_prime(sieve);
        printf("%d ", prime);
        mark_non_primes(sieve, prime);
        count++;
    }
    free(sieve->array);
    free(sieve);
    return 0;
}