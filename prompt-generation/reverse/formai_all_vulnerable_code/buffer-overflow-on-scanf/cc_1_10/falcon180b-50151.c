//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM 1000000

int is_prime(int num);
void sieve_of_eratosthenes(int *arr, int n);

int main() {
    int n, i, j, count = 0;
    int *arr = (int *)malloc(MAX_NUM * sizeof(int));
    srand(time(NULL));

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    for (i = 2; i <= MAX_NUM; i++) {
        arr[i] = true;
    }

    sieve_of_eratosthenes(arr, MAX_NUM);

    printf("\nFirst %d prime numbers:\n", n);

    for (i = 2; count < n; i++) {
        if (arr[i]) {
            printf("%d ", i);
            count++;
        }
    }

    free(arr);
    return 0;
}

int is_prime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

void sieve_of_eratosthenes(int *arr, int n) {
    int i, j;

    for (i = 2; i <= n; i++) {
        if (arr[i]) {
            for (j = i * i; j <= n; j += i) {
                arr[j] = false;
            }
        }
    }
}