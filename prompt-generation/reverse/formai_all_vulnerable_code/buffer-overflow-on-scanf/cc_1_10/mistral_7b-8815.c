//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100000

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int limit) {
    int *numbers = (int *)calloc(limit, sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int count = 0;
    for (int i = 2; count < limit; i++) {
        if (is_prime(i)) {
            numbers[count++] = i;
        }
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
}

int main() {
    srand(time(NULL));

    int limit;
    printf("Enter the limit for prime numbers: ");
    scanf("%d", &limit);

    print_primes(limit);

    return 0;
}