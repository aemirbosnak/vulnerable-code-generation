//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRIME_NUMBERS 1000
#define MAX_PRIME_FACTORS 1000

typedef struct {
    int prime_number;
    int prime_factors[MAX_PRIME_FACTORS];
    int num_prime_factors;
} PrimeNumber;

PrimeNumber generate_prime_number(int num_prime_factors) {
    PrimeNumber prime_number;
    int i, j;
    srand(time(NULL));

    prime_number.prime_number = rand() % 10000 + 1;
    prime_number.num_prime_factors = num_prime_factors;
    prime_number.prime_factors[0] = 1;

    for (i = 1; i < num_prime_factors; i++) {
        int is_prime = 1;
        while (is_prime) {
            prime_number.prime_factors[i] = rand() % (prime_number.prime_number - 1) + 2;
            is_prime = 1;
            for (j = 0; j < i; j++) {
                if (prime_number.prime_factors[j] == prime_number.prime_factors[i]) {
                    is_prime = 0;
                    break;
                }
            }
        }
    }

    return prime_number;
}

int main(int argc, char *argv[]) {
    int num_prime_factors;
    int i;

    printf("Enter the number of prime factors: ");
    scanf("%d", &num_prime_factors);

    PrimeNumber prime_number = generate_prime_number(num_prime_factors);

    printf("Prime number: %d\n", prime_number.prime_number);
    printf("Prime factors:");

    for (i = 0; i < prime_number.num_prime_factors; i++) {
        printf(" %d", prime_number.prime_factors[i]);
    }

    printf("\n");

    return 0;
}