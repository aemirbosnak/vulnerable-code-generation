//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NUMBERS 1000
#define MIN_PRIME 2
#define MAX_PRIME 1000

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_prime_numbers(int numbers[], int count) {
    int i, j, prime;
    for (i = 0; i < count; i++) {
        prime = 0;
        while (!prime) {
            numbers[i] = rand() % MAX_PRIME + MIN_PRIME;
            prime = is_prime(numbers[i]);
        }
    }
}

int main() {
    int players, numbers[MAX_NUMBERS];
    printf("Enter the number of players: ");
    scanf("%d", &players);

    if (players < 2 || players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &numbers[0]);

    if (numbers[0] < 1 || numbers[0] > MAX_NUMBERS) {
        printf("Invalid number of prime numbers.\n");
        return 1;
    }

    generate_prime_numbers(numbers, numbers[0]);

    printf("Prime numbers:\n");
    for (int i = 0; i < numbers[0]; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
    return 0;
}