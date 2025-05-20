//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000

int a[MAX];
int n;

void sieve() {
    int i, j, k;
    for (i = 2; i <= sqrt(MAX); i++) {
        if (a[i] == 0) {
            for (j = i*i; j <= MAX; j += i) {
                a[j] = 1;
            }
        }
    }
    for (i = 2; i <= MAX; i++) {
        if (a[i] == 0) {
            k = i;
            while (k <= MAX) {
                a[k] = 1;
                k += i;
            }
        }
    }
}

void printArray() {
    int i;
    for (i = 2; i <= MAX; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
        }
    }
}

int main() {
    int i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    sieve();
    printf("Prime numbers up to %d:\n", n);
    for (i = 2; i <= n; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}