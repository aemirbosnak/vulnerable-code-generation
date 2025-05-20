//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRIME 1000000
#define MAX_VALUE 1000000000

int isPrime(int n);
int generateRandomPrime(void);
int generateRandomNumber(int max);
void encrypt(int plaintext, int key, int* ciphertext);
void decrypt(int ciphertext, int key, int* plaintext);

int main() {
    int plaintext, key, ciphertext, decrypted;
    printf("Enter the plaintext: ");
    scanf("%d", &plaintext);
    printf("Enter the key: ");
    scanf("%d", &key);
    if (isPrime(key) == 0) {
        printf("Key must be a prime number.\n");
        return 1;
    }
    encrypt(plaintext, key, &ciphertext);
    printf("Ciphertext: %d\n", ciphertext);
    decrypt(ciphertext, key, &decrypted);
    printf("Decrypted text: %d\n", decrypted);
    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generateRandomPrime() {
    int randNum;
    do {
        randNum = rand() % MAX_PRIME;
    } while (!isPrime(randNum));
    return randNum;
}

int generateRandomNumber(int max) {
    int randNum;
    do {
        randNum = rand() % max;
    } while (randNum == 0);
    return randNum;
}

void encrypt(int plaintext, int key, int* ciphertext) {
    int temp = plaintext;
    *ciphertext = 0;
    while (temp!= 0) {
        int digit = temp % 10;
        temp /= 10;
        *ciphertext = (*ciphertext * 10) + (digit ^ key);
    }
}

void decrypt(int ciphertext, int key, int* plaintext) {
    int temp = ciphertext;
    *plaintext = 0;
    while (temp!= 0) {
        int digit = temp % 10;
        temp /= 10;
        *plaintext = (*plaintext * 10) + (digit ^ key);
    }
}