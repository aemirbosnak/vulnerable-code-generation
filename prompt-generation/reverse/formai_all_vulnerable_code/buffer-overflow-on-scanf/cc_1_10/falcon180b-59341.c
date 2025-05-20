//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define PRIME_NUM 1
#define COMPOSITE_NUM 0

int is_prime(int num);
int main(void) {
    int num, choice, count = 0;
    char again;

    srand(time(NULL));
    printf("Welcome to the Prime Number Generator!\n\n");
    printf("Please enter a number to check if it is prime: ");
    scanf("%d", &num);

    if (is_prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    printf("Would you like to check another number? (y/n): ");
    scanf(" %c", &again);

    while (again == 'y' || again == 'Y') {
        printf("Please enter a number to check if it is prime: ");
        scanf("%d", &num);

        if (is_prime(num)) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("%d is not a prime number.\n", num);
        }

        printf("Would you like to check another number? (y/n): ");
        scanf(" %c", &again);
    }

    return 0;
}

int is_prime(int num) {
    int i, status = PRIME_NUM;

    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            status = COMPOSITE_NUM;
            break;
        }
    }

    return status;
}