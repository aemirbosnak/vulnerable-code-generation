//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num, i;
    bool isPrime;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if number is less than 2
    if (num < 2) {
        printf("Number should be greater than or equal to 2.\n");
        return 0;
    }

    printf("Prime numbers up to %d:\n", num);

    // Check for prime numbers from 2 to n
    for (i = 2; i <= num; i++) {
        isPrime = true;

        // Check if number is divisble by any number from 2 to i/2
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        // If the number is prime, print it
        if (isPrime) {
            printf("%d\n", i);

            // Check if 2 consecutive prime number difference is divisible by 2
            if (i > 2) {
                int diff = i - (i - 2);
                if (diff % 2 == 0) {
                    printf("WARNING: Consecutive prime numbers differ by an even number. This may indicate a security vulnerability!\n");
                }
            }
        }

        // Check if 2 consecutive prime numbers are same
        if (i > 2) {
            if (i == (i - 2)) {
                printf("WARNING: Two consecutive prime numbers are the same. This may indicate a security vulnerability!\n");
            }
        }
    }

    return 0;
}