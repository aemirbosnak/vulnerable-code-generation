//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000

bool is_prime(int num);
void sieve_of_eratosthenes(int arr[], int n);
void print_primes(int arr[], int n);

int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    sieve_of_eratosthenes(arr, n);
    printf("\nPrime numbers between 1 and %d:\n", n);
    print_primes(arr, n);
    return 0;
}

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void sieve_of_eratosthenes(int arr[], int n) {
    int i, j;
    for (i = 2; i <= n / 2; i++) {
        if (arr[i] == i) {
            for (j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
}

void print_primes(int arr[], int n) {
    int i;
    for (i = 2; i <= n; i++) {
        if (arr[i] == i) {
            printf("%d ", i);
        }
    }
}