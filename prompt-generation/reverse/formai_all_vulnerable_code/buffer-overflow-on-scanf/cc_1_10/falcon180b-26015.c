//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 100
#define MAX_PRIME_SIZE 100

typedef struct {
    int num;
    int prime;
} Number;

void generatePrime(int* prime, int num) {
    int i;
    for (i = 2; i <= num; i++) {
        if (num % i == 0) {
            *prime = i;
            break;
        }
    }
}

int isPrime(int num) {
    int i;
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePublicKey(Number* publicKey, int num) {
    int i;
    for (i = 2; i <= num; i++) {
        if (isPrime(i)) {
            publicKey->prime = i;
            publicKey->num = num;
            break;
        }
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    Number publicKey;
    generatePublicKey(&publicKey, num);

    printf("Public key: (%d, %d)\n", publicKey.num, publicKey.prime);

    return 0;
}