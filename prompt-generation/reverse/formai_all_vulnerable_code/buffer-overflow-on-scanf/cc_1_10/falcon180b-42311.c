//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int is_prime(int num) {
    int i;
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int num) {
    int i, j, count = 0;
    int *primes = (int *)malloc(MAX_NUM * sizeof(int));

    primes[count++] = 2;

    for(i = 3; count < num; i += 2) {
        if(is_prime(i)) {
            primes[count++] = i;
        }
    }

    printf("Prime numbers up to %d:\n", num);
    for(i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
}

int main() {
    int num;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    if(num <= 0 || num > MAX_NUM) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUM);
        return 1;
    }

    generate_primes(num);

    return 0;
}