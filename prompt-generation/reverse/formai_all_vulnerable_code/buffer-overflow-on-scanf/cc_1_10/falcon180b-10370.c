//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM 10000000
#define MAX_PRIMES 1000

int primes[MAX_PRIMES];
int num_primes = 0;

void generate_primes() {
    int i, j;
    bool is_prime;
    srand(time(NULL));
    for (i = 2; num_primes < MAX_PRIMES; i++) {
        is_prime = true;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes[num_primes++] = i;
        }
    }
}

int main() {
    int start_num, end_num, i;

    printf("Enter start number: ");
    scanf("%d", &start_num);
    printf("Enter end number: ");
    scanf("%d", &end_num);

    if (start_num > end_num) {
        printf("Invalid range.\n");
        exit(1);
    }

    generate_primes();

    printf("Prime numbers between %d and %d:\n", start_num, end_num);
    for (i = 0; i < num_primes; i++) {
        if (primes[i] >= start_num && primes[i] <= end_num) {
            printf("%d ", primes[i]);
        }
    }

    return 0;
}