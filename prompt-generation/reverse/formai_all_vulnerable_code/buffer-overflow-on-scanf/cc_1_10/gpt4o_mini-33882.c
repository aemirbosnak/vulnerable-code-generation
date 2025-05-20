//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int number) {
    if (number <= 1) return 0;
    if (number <= 3) return 1;
    if (number % 2 == 0 || number % 3 == 0) return 0;
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return 0;
    }
    return 1;
}

void generate_primes(int limit, int **primes, int *count) {
    *count = 0;
    *primes = (int *)malloc(sizeof(int) * limit);

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            (*primes)[(*count)++] = i;
        }
    }
}

void print_statistics(int *primes, int count) {
    if (count == 0) {
        printf("No prime numbers were generated.\n");
        return;
    }

    int sum = 0;
    double mean, variance = 0.0;

    for (int i = 0; i < count; i++) {
        sum += primes[i];
    }
    mean = (double)sum / count;

    for (int i = 0; i < count; i++) {
        variance += (primes[i] - mean) * (primes[i] - mean);
    }
    variance /= count;

    double stddev = sqrt(variance);

    printf("Statistics of Generated Prime Numbers:\n");
    printf("Total Count: %d\n", count);
    printf("Sum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
}

void free_memory(int *primes) {
    free(primes);
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    int *primes = NULL;
    int count = 0;

    generate_primes(limit, &primes, &count);
    
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    if (count % 10 != 0) printf("\n");

    print_statistics(primes, count);
    free_memory(primes);

    return 0;
}