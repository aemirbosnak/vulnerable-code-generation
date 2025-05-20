//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100000

bool is_prime[MAX + 1];

void sieve(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int limit, a, b, c;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    sieve(limit);

    printf("Primes up to %d:\n", limit);

    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    printf("Enter three numbers to check if they form a prime triangle:\n");
    scanf("%d%d%d", &a, &b, &c);

    if (a > b + c || b > a + c || c > a + b) {
        printf("Invalid input.\n");
    } else if (is_prime[a] && is_prime[b] && is_prime[c]) {
        printf("%d, %d, %d is a prime triangle.\n", a, b, c);
    } else {
        printf("%d, %d, %d is not a prime triangle.\n", a, b, c);
    }

    return 0;
}

// A prime triangle is a triangle whose sides are prime numbers.