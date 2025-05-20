//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0

int is_prime(int n);
void sieve_of_eratosthenes(int limit);

int main() {
    int i, j, count = 0, limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);
    printf("Prime numbers up to %d:\n", limit);
    for (i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        if (count == 50) {
            break;
        }
    }
    printf("\nTotal prime numbers generated: %d\n", count);
    return 0;
}

int is_prime(int n) {
    int i;
    if (n <= 1) {
        return FALSE;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void sieve_of_eratosthenes(int limit) {
    int i, j, is_composite[MAX] = { FALSE };
    for (i = 2; i <= sqrt(limit); i++) {
        if (!is_composite[i]) {
            for (j = i * i; j <= limit; j += i) {
                is_composite[j] = TRUE;
            }
        }
    }
    printf("Prime numbers up to %d:\n", limit);
    for (i = 2; i <= limit; i++) {
        if (!is_composite[i]) {
            printf("%d ", i);
        }
    }
}