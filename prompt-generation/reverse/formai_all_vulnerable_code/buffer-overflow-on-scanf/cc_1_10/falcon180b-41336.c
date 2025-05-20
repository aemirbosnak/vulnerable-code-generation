//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 1000000
#define MAX_PRIMES 10000

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int start_num, int end_num) {
    int count = 0;
    int num = start_num;
    while (count < MAX_PRIMES && num <= end_num) {
        if (is_prime(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
}

int main() {
    int start_num, end_num;
    printf("Enter the starting number: ");
    scanf("%d", &start_num);
    printf("Enter the ending number: ");
    scanf("%d", &end_num);

    if (start_num < 2) {
        start_num = 2;
    }
    if (end_num > MAX_NUMBERS) {
        end_num = MAX_NUMBERS;
    }

    printf("Generating prime numbers between %d and %d...\n", start_num, end_num);
    generate_primes(start_num, end_num);

    return 0;
}