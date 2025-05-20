//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000

int is_prime(int num);
void generate_primes(int start_num);

int main() {
    int start_num;

    printf("Enter the starting number: ");
    scanf("%d", &start_num);

    if (start_num < 2) {
        printf("Invalid starting number.\n");
        return 1;
    }

    generate_primes(start_num);

    return 0;
}

int is_prime(int num) {
    int i;

    if (num <= 1) {
        return 0;
    }

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void generate_primes(int start_num) {
    int num, count = 0;

    printf("Prime numbers between %d and %d:\n", start_num, MAX_NUM);

    for (num = start_num; num <= MAX_NUM; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;

            if (count == 10) {
                printf("\n");
                count = 0;
            }
        }
    }

    if (count > 0) {
        printf("\n");
    }
}