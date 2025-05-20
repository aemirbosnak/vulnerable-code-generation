//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LEN 100

// Function to generate a random key
void generate_key(int key[], int n) {
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < n; i++) {
        key[i] = rand() % 256; // generate a random number between 0 and 255
    }
}

// Function to encrypt the plaintext using the key
void encrypt(char plaintext[], int len, int key[], int n) {
    for (int i = 0; i < len; i++) {
        plaintext[i] ^= key[i % n]; // XOR the plaintext with the key
    }
}

// Function to decrypt the ciphertext using the key
void decrypt(char ciphertext[], int len, int key[], int n) {
    for (int i = 0; i < len; i++) {
        ciphertext[i] ^= key[i % n]; // XOR the ciphertext with the key
    }
}

int main() {
    char plaintext[MAX_LEN];
    int key[MAX_LEN], key_len;

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LEN, stdin); // read the plaintext

    printf("Enter the length of the key: ");
    scanf("%d", &key_len); // read the length of the key

    generate_key(key, key_len); // generate the key

    encrypt(plaintext, strlen(plaintext), key, key_len); // encrypt the plaintext

    printf("Encrypted text: %s", plaintext);

    decrypt(plaintext, strlen(plaintext), key, key_len); // decrypt the ciphertext

    printf("Decrypted text: %s", plaintext);

    return 0;
}