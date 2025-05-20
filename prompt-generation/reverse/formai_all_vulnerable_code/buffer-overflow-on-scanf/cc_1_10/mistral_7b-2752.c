//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 1000 // Maximum number to check

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int i = 5;
    int w = 2;

    while (i * i <= n) {
        if (n % i == 0) return false;
        i += w;
        w = 6 - w;
    }

    return true;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (is_prime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    printf("Now, let us find some prime Romeos and Juliets.\n");
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime(i)) {
            printf("%d is a prime Romeo.\n", i);
            int j;
            for (j = i + 1; j <= MAX; ++j) {
                if (is_prime(j)) {
                    printf("%d is a prime Juliet for %d.\n", j, i);
                    break;
                }
            }
            if (j > MAX) {
                printf("%d has no prime Juliet.\n", i);
            }
        }
    }

    return 0;
}