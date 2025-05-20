//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000 // maximum number to be tested
#define SEED 12345 // seed value for srand()

int isPrime(int n) {
    int i;
    if (n < 2) {
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int start, int end) {
    int i, j;
    for (i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    srand(SEED); // seed the random number generator
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    if (start > end) {
        printf("Invalid range\n");
        return 0;
    }
    if (start < 2) {
        start = 2;
    }
    if (end > MAX) {
        end = MAX;
    }
    generatePrimes(start, end);
    return 0;
}