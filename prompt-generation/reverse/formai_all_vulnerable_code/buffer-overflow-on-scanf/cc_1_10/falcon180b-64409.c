//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    int i, flag = 0;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return 1;
    else
        return 0;
}

void sieveOfEratosthenes(int n) {
    int i, j, count = 0;
    int prime[n + 1];
    prime[0] = 0;
    prime[1] = 0;
    for (i = 2; i <= n; i++) {
        prime[i] = 1;
    }
    for (i = 2; i * i <= n; i++) {
        if (prime[i] == 1) {
            for (j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal prime numbers: %d", count);
}

int main() {
    int n, num, count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("\nThe first %d prime numbers are:\n", n);
    for (num = 2; count < n; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
    }
    printf("\n");
    return 0;
}