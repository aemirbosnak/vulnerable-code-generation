//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 1024 // Key length
#define BASE 5 // Base of the number system

// Function to generate a random number in the range [0, n-1]
int randint(int n) {
    return rand() % n;
}

// Function to generate a random prime number in the range [2, n-1]
int randprime(int n) {
    int x;
    do {
        x = randint(n);
    } while (x == 2 ||!isprime(x));
    return x;
}

// Function to check if a number is prime
int isprime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random key
void generatekey(int *key) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = randprime(BASE);
    }
}

// Function to encrypt a message using the public key
void encrypt(int *pubkey, char *message) {
    int i, j;
    int key[SIZE];
    for (i = 0; i < SIZE; i++) {
        key[i] = pubkey[i];
    }
    int m = strlen(message);
    char *encrypted = (char *)malloc(m + 1);
    encrypted[0] = '\0';
    for (i = 0; i < m; i++) {
        encrypted[i] = message[i];
    }
    for (i = 0; i < m; i++) {
        encrypted[i] = encrypted[i] % BASE;
    }
    for (i = 0; i < m; i++) {
        encrypted[i] = encrypted[i] * key[i] % BASE;
    }
    encrypted[m] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

// Function to decrypt a message using the private key
void decrypt(int *privkey, char *message) {
    int i, j;
    int key[SIZE];
    for (i = 0; i < SIZE; i++) {
        key[i] = privkey[i];
    }
    int m = strlen(message);
    char *decrypted = (char *)malloc(m + 1);
    decrypted[0] = '\0';
    for (i = 0; i < m; i++) {
        decrypted[i] = message[i];
    }
    for (i = 0; i < m; i++) {
        decrypted[i] = decrypted[i] % key[i];
    }
    for (i = 0; i < m; i++) {
        decrypted[i] = decrypted[i] * BASE % key[i];
    }
    decrypted[m] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    int pubkey[SIZE], privkey[SIZE];
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    generatekey(pubkey);
    generatekey(privkey);
    encrypt(pubkey, message);
    decrypt(privkey, message);
    return 0;
}