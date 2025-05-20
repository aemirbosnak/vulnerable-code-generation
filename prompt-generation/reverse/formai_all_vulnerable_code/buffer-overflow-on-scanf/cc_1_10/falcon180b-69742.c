//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_PRIMES 1000
#define MAX_NUM_TESTS 100

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int *primes, int num_primes) {
    int count = 0;
    int num = 2;
    while (count < num_primes) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
        num++;
    }
}

int main() {
    srand(time(NULL));

    int num_primes;
    printf("Enter the number of primes to generate: ");
    scanf("%d", &num_primes);

    int *primes = malloc(sizeof(int) * num_primes);
    generate_primes(primes, num_primes);

    printf("Generated %d primes:\n", num_primes);
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    int num_tests;
    printf("Enter the number of tests to run: ");
    scanf("%d", &num_tests);

    int correct = 0;
    for (int i = 0; i < num_tests; i++) {
        int num1 = rand() % 1000 + 1;
        int num2 = rand() % 1000 + 1;

        if (is_prime(num1) && is_prime(num2)) {
            int result = (num1 * num2) % 1000;
            printf("Test %d: %d * %d = %d (mod 1000)\n", i + 1, num1, num2, result);
            correct += result == (num1 * num2) % 1000;
        } else {
            printf("Test %d: Skipped (not both prime)\n", i + 1);
        }
    }

    printf("Passed %d out of %d tests\n", correct, num_tests);

    free(primes);
    return 0;
}