//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int num);

int main() {
    srand(time(NULL));
    int num;
    int count = 0;
    int max = 1000000;
    int min = 1000;
    int range = max - min + 1;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);

    printf("\n");

    for (int i = 0; i < num; i++) {
        int number = rand() % range + min;
        while (!isPrime(number)) {
            number = rand() % range + min;
        }
        printf("%d\n", number);
        count++;
    }

    if (count == num) {
        printf("\n%d prime numbers generated successfully!\n", num);
    } else {
        printf("\nFailed to generate %d prime numbers.\n", num);
    }

    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}