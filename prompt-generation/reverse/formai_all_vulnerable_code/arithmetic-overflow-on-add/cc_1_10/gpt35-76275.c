//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Welcome to the Prime Number Generator\n");
    printf("Sit back, relax and enjoy the surreal ride\n");
    printf("\n");

    waitFor(2);

    printf("Loading...\n");
    printf("\n");

    waitFor(3);

    printf("Generating primes...\n");
    printf("\n");

    waitFor(2);

    srand(time(NULL));

    for (int i = 0; i < 50; i++) {
        int num = rand() % 10000;
        if (isPrime(num)) {
            printf("%d: prime\n", num);
        } else {
            printf("%d: not prime\n", num);
        }
        waitFor(rand() % 3);
        printf("\n");
    }

    printf("Prime number generation complete!\n");
    printf("\n");
    printf("Thank you for riding the surreal wave of prime numbers\n");

    return 0;
}