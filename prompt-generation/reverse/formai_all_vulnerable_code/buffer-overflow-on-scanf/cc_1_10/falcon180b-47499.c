//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

int main() {

    int n, m;
    bool isPrime = true;
    double pi = 0;
    double sum = 0;
    double term = 1;
    int count = 0;
    time_t start, end;
    double elapsed;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        m = i;
        while (m % 2 == 0) {
            m /= 2;
        }
        if (m == 1) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        printf("%d is a prime number.\n", n);
    }
    else {
        printf("%d is not a prime number.\n", n);
    }

    printf("Enter the number of terms for the sum of pi: ");
    scanf("%d", &count);

    time(&start);

    for (int i = 0; i < count; i++) {
        sum += term;
        term *= -1;
    }

    time(&end);
    elapsed = difftime(end, start);

    printf("The sum of pi for %d terms is: %.10f\n", count, sum);
    printf("Time elapsed: %.10f seconds\n", elapsed);

    return 0;
}