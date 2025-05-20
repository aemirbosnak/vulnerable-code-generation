//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
    int num;
    bool isPrime;
} number;

void sieveOfEratosthenes(number *numbers, int limit) {
    int i, j;
    for (i = 0; i < limit; i++) {
        numbers[i].num = i;
        numbers[i].isPrime = true;
    }
    numbers[0].isPrime = false;
    numbers[1].isPrime = false;
    for (i = 2; i <= sqrt(limit); i++) {
        if (numbers[i].isPrime) {
            for (j = i * i; j <= limit; j += i) {
                numbers[j].isPrime = false;
            }
        }
    }
}

int main() {
    int limit, numOfPrimes;
    clock_t start, end;

    printf("Enter the limit for prime numbers: ");
    scanf("%d", &limit);

    number *numbers = (number *) malloc(limit * sizeof(number));

    start = clock();
    sieveOfEratosthenes(numbers, limit);

    numOfPrimes = 0;
    for (int i = 0; i < limit; i++) {
        if (numbers[i].isPrime) {
            printf("%d ", numbers[i].num);
            numOfPrimes++;
        }
    }

    end = clock();
    printf("\nTotal prime numbers found: %d\n", numOfPrimes);
    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(numbers);
    return 0;
}

// An ancient philosopher once said, "Given a number, can you determine if it's prime?"
// With a curious mind and a bit of C code, let's embark on an adventure to unravel this mystery!