//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUM 1000000
#define MAX_PRIMES 100

int is_prime(int num);
void generate_primes(int num);

int main(void) {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 2) {
        printf("Invalid input. Please enter a number greater than or equal to 2.\n");
        return 1;
    }

    printf("Generating prime numbers up to %d...\n", num);
    generate_primes(num);

    return 0;
}

int is_prime(int num) {
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

void generate_primes(int num) {
    int primes[MAX_PRIMES];
    int count = 0;

    primes[count++] = 2;

    for (int i = 3; i <= num; i += 2) {
        if (is_prime(i)) {
            primes[count++] = i;

            if (count >= MAX_PRIMES) {
                break;
            }
        }
    }

    printf("Prime numbers up to %d:\n", num);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}