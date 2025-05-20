//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000000
#define TRUE 1
#define FALSE 0

int isPrime(int num);

int main() {
    int start, end, num, count = 0;

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid range\n");
        return 0;
    }

    printf("\nPrime numbers between %d and %d:\n", start, end);

    for (num = start; num <= end; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo prime numbers found in the given range\n");
    }

    return 0;
}

int isPrime(int num) {
    int i;

    if (num <= 1) {
        return FALSE;
    }

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return FALSE;
        }
    }

    return TRUE;
}