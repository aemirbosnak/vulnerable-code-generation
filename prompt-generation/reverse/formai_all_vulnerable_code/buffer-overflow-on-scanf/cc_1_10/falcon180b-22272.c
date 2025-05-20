//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 10000000
#define PRIME_NUM 1000

int isPrime(int num);
int generatePrime(int num);

int main() {
    int num, i;
    srand(time(NULL));

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);

    printf("Generating %d prime numbers...\n", num);

    for (i = 0; i < num; i++) {
        int prime = generatePrime(MAX_NUM);
        printf("%d ", prime);
    }

    return 0;
}

int isPrime(int num) {
    if (num <= 1)
        return 0;
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int generatePrime(int num) {
    int i = 0;
    while (i < PRIME_NUM) {
        int randomNum = rand() % num + 1;
        if (isPrime(randomNum)) {
            return randomNum;
        }
        i++;
    }
    return 0;
}