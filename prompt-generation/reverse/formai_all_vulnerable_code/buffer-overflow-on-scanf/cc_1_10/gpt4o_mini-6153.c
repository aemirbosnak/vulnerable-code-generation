//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10000

void flash(int n) {
    const char *stars = "\033[1;33m*\033[0m";
    printf("Prime Numbers up to %d:\n", n);
    for (int i = 0; i < n; i++)
        printf("%s", stars);
    printf("\n");
}

bool shadow(int num) {
    if (num < 2) 
        return false;
    for (int i = 2; i * i <= num; i++) 
        if (num % i == 0) 
            return false;
    return true;
}

void dance_of_primes(int limit) {
    int count = 0;
    int *primes = (int *)malloc(MAX * sizeof(int));

    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i <= limit; i++) {
        if (shadow(i)) {
            primes[count++] = i;
        }
    }

    printf("Found %d prime numbers:\n", count);
    for (int j = 0; j < count; j++)
        printf("%d ", primes[j]);
    printf("\n");

    free(primes);
}

void enigma() {
    int threshold;
    printf("Enter the upper bound for prime generation (up to %d): ", MAX);
    scanf("%d", &threshold);
    if (threshold < 1 || threshold > MAX) {
        fprintf(stderr, "Please provide a number between 1 and %d.\n", MAX);
        exit(EXIT_FAILURE);
    }
    flash(threshold);
    dance_of_primes(threshold);
}

char* whisper() {
    return "Feel the rhythm of the primes!";
}

int main() {
    printf("%s\n", whisper());
    enigma();
    return 0;
}