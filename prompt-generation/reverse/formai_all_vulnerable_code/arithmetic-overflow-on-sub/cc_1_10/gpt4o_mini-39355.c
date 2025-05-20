//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void save_primes_to_file(int *primes, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d\n", primes[i]);
    }
    fclose(file);
}

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void generate_primes(int limit, int *primes, int *count) {
    *count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[*count] = i;
            (*count)++;
        }
    }
}

int main() {
    int limit, count;
    printf("Enter the upper limit for prime number generation: ");
    scanf("%d", &limit);

    int *primes = (int *)malloc(limit * sizeof(int));
    if (primes == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    clock_t start_time = clock();
    generate_primes(limit, primes, &count);
    clock_t end_time = clock();

    printf("Generated %d prime numbers up to %d:\n", count, limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to generate prime numbers: %f seconds\n", time_taken);

    const char *filename = "primes.txt";
    save_primes_to_file(primes, count, filename);
    printf("Prime numbers saved to '%s'\n", filename);

    free(primes);
    return 0;
}