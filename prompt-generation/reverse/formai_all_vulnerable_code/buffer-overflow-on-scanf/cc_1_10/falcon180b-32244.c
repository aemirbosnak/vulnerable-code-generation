//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_KEY_LEN 32
#define MAX_DATA_LEN 1024
#define MAX_ROUNDS 1000000

// Function to encrypt the data
void encrypt(char* key, char* data, int rounds) {
    int i, j, len = strlen(data);
    char* encrypted_data = malloc(len + 1);
    for (i = 0; i < len; i++) {
        encrypted_data[i] = data[i];
    }
    encrypted_data[len] = '\0';
    for (i = 0; i < rounds; i++) {
        for (j = 0; j < len; j++) {
            encrypted_data[j] = encrypted_data[j] ^ key[i % strlen(key)];
        }
    }
    printf("Encrypted data: %s\n", encrypted_data);
}

// Function to decrypt the data
void decrypt(char* key, char* data, int rounds) {
    int i, j, len = strlen(data);
    char* decrypted_data = malloc(len + 1);
    for (i = 0; i < len; i++) {
        decrypted_data[i] = data[i];
    }
    decrypted_data[len] = '\0';
    for (i = 0; i < rounds; i++) {
        for (j = 0; j < len; j++) {
            decrypted_data[j] = decrypted_data[j] ^ key[i % strlen(key)];
        }
    }
    printf("Decrypted data: %s\n", decrypted_data);
}

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

int main() {
    char* data;
    char* key;
    int rounds;

    // Get the data from the user
    printf("Enter the data to be encrypted/decrypted: ");
    scanf("%s", data);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Get the number of rounds for encryption/decryption
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    // Encrypt the data
    encrypt(key, data, rounds);

    // Decrypt the encrypted data
    decrypt(key, data, rounds);

    return 0;
}