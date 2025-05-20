//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000

int isPrime(int num) {
    if(num <= 1) {
        return 0;
    }
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int start, int end) {
    printf("Prime numbers between %d and %d:\n", start, end);
    for(int i=start; i<=end; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Enter start number: ");
    scanf("%d", &start);

    printf("Enter end number: ");
    scanf("%d", &end);

    if(start > end) {
        printf("Invalid input. Start number cannot be greater than end number.\n");
        return 0;
    }

    if(start < 2) {
        start = 2;
    }

    if(end > MAX_NUM) {
        end = MAX_NUM;
    }

    generatePrimes(start, end);

    return 0;
}