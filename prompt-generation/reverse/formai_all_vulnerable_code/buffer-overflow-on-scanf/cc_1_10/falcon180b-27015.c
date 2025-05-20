//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int num);
int *generatePrimes(int numPrimes, int min, int max);
void printArray(int *arr, int size);

int main() {
    int numPrimes, min, max;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &numPrimes);
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    srand(time(NULL));
    int *primes = generatePrimes(numPrimes, min, max);
    printf("\n%d prime numbers between %d and %d:\n", numPrimes, min, max);
    printArray(primes, numPrimes);

    return 0;
}

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int *generatePrimes(int numPrimes, int min, int max) {
    int *primes = (int *) malloc(numPrimes * sizeof(int));
    int count = 0;
    int num;

    while (count < numPrimes) {
        num = rand() % (max - min + 1) + min;
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
    }

    return primes;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}