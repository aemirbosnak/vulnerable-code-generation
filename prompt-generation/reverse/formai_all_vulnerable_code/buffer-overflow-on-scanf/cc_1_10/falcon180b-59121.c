//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 1000000

int is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generate_primes(int start, int end) {
    printf("Prime numbers between %d and %d:\n", start, end);

    int count = 0;
    int num;

    for (num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }

        if (count == MAX_NUM) {
            printf("\nToo many prime numbers, exiting...\n");
            exit(0);
        }
    }
}

int main() {
    int start, end;

    printf("Enter start number: ");
    scanf("%d", &start);

    printf("Enter end number: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid input, please enter a valid range.\n");
        exit(1);
    }

    generate_primes(start, end);

    return 0;
}