//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int is_prime(int n);
int find_next_prime(int n);
int generate_prime(int n);

int main() {
    int n;
    srand(time(NULL));
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("Generating %d prime numbers...\n", n);

    for (int i = 0; i < n; i++) {
        int prime = generate_prime(i+1);
        printf("%d. %d\n", i+1, prime);
    }

    return 0;
}

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

int find_next_prime(int n) {
    int count = 0;
    while (!is_prime(n)) {
        n++;
        count++;
        if (count > 10000) {
            printf("Error: No prime found after 10000 attempts.\n");
            exit(1);
        }
    }
    return n;
}

int generate_prime(int n) {
    int prime = find_next_prime(n);
    printf("Prime %d: %d\n", n, prime);
    return prime;
}