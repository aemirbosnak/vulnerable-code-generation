//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define TRUE 1
#define FALSE 0

int isPrime(int num) {
    int i;

    if (num == 1)
        return FALSE;

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return FALSE;
    }

    return TRUE;
}

int main(void) {
    int num, count = 0, primes[MAX_NUM] = {0};
    int start, end, step;
    time_t seed;
    int i;

    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &num);

    if (num > MAX_NUM) {
        printf("Error: Number of primes exceeds the maximum limit.\n");
        exit(1);
    }

    printf("Enter the range for prime numbers (start, end): ");
    scanf("%d %d", &start, &end);

    if (start < 2 || end < start) {
        printf("Error: Invalid range for prime numbers.\n");
        exit(1);
    }

    printf("Enter the step for prime numbers: ");
    scanf("%d", &step);

    srand(time(&seed));

    for (i = start; i <= end; i += step) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    printf("Prime numbers generated:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}