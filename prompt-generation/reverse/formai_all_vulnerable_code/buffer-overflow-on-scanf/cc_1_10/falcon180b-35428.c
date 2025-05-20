//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to generate random prime number
int is_prime(int n) {
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int i;
    for (i = 0; i < 2; i++) {
        do {
            *public_key = rand() % MAX_SIZE;
            *private_key = rand() % MAX_SIZE;
        } while (!is_prime(*public_key) ||!is_prime(*private_key));
    }
}

// Function to encrypt message using public key
void encrypt(char *message, int public_key, char *ciphertext) {
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            ciphertext[j++] = (char) ((int) message[i] + public_key - 97 % 26 + 97);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            ciphertext[j++] = (char) ((int) message[i] + public_key - 65 % 26 + 65);
        } else {
            ciphertext[j++] = message[i];
        }
    }
    ciphertext[j] = '\0';
}

// Function to decrypt ciphertext using private key
void decrypt(char *ciphertext, int private_key, char *message) {
    int i, j, k;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            message[j++] = (char) ((int) ciphertext[i] - private_key - 97 % 26 + 97);
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            message[j++] = (char) ((int) ciphertext[i] - private_key - 65 % 26 + 65);
        } else {
            message[j++] = ciphertext[i];
        }
    }
    message[j] = '\0';
}

int main() {
    int public_key, private_key;
    char message[MAX_SIZE], ciphertext[MAX_SIZE];
    generate_keys(&public_key, &private_key);
    printf("Public Key: %d\nPrivate Key: %d\n", public_key, private_key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, public_key, ciphertext);
    printf("Encrypted Message: %s\n", ciphertext);
    printf("Decrypted Message: ");
    decrypt(ciphertext, private_key, message);
    printf("%s\n", message);
    return 0;
}