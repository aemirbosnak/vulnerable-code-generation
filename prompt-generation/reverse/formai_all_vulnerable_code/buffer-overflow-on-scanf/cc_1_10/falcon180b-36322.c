//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX 1000000

int isPrime(int n);
void generatePrimes(int *arr, int size);
void printArray(int *arr, int size);

int main() {
    int arr[MAX];
    int size = 0;
    int n;

    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 2; i <= MAX; i++) {
        if (isPrime(i)) {
            arr[size++] = i;
            if (size == n) {
                break;
            }
        }
    }

    printf("Generated %d primes:\n", n);
    printArray(arr, n);

    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void generatePrimes(int *arr, int size) {
    int n = rand() % MAX + 2;

    while (true) {
        if (isPrime(n)) {
            arr[size++] = n;
            break;
        }
        n = rand() % MAX + 2;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}