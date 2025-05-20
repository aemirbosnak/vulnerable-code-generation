//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <math.h>

#define MAX_NUM 1000000
#define PRIMES_PER_LINE 10

int isPrime(int num) {
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

void generatePrimes(int startNum, int endNum) {
    printf("Generating primes between %d and %d...\n", startNum, endNum);
    int count = 0;
    for (int num = startNum; num <= endNum; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            if (++count == PRIMES_PER_LINE) {
                printf("\n");
                count = 0;
            }
        }
    }
    if (count!= 0) {
        printf("\n");
    }
}

int main() {
    int startNum, endNum;
    printf("Enter start number: ");
    scanf("%d", &startNum);
    printf("Enter end number: ");
    scanf("%d", &endNum);
    if (startNum > endNum) {
        printf("Invalid input. Start number cannot be greater than end number.\n");
        return 1;
    }
    if (startNum < 2) {
        startNum = 2;
    }
    if (endNum > MAX_NUM) {
        endNum = MAX_NUM;
    }
    generatePrimes(startNum, endNum);
    return 0;
}