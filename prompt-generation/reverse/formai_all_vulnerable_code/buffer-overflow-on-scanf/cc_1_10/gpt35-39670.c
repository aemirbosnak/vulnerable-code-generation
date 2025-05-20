//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>

int is_prime(int n) {
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    int i = 5;
    int w = 2;

    while (i * i <= n) {
        if (n % i == 0)
            return 0;

        i += w;
        w = 6 - w;
    }

    return 1;
}

void generate_primes(int n) {
    if (n < 2) {
        printf("There are no prime numbers less than %d\n", n);
        return;
    }

    printf("The first %d prime numbers are:\n", n);

    int count = 0;
    int i = 2;

    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }

        i++;
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &n);

    generate_primes(n);

    return 0;
}