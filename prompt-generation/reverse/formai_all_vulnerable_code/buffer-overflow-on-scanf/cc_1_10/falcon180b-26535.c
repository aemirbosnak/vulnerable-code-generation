//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 32
#define MAX_DATA_LEN 1024

// Generates a random key of length keylen
void generate_key(char *key, int keylen) {
    srand(time(NULL));
    for (int i = 0; i < keylen; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// XORs two strings of equal length
void xor_strings(char *str1, char *str2, int len) {
    for (int i = 0; i < len; i++) {
        str1[i] ^= str2[i];
    }
}

// Encrypts the given data using the provided key
void encrypt_data(char *data, int datalen, char *key) {
    for (int i = 0; i < datalen; i++) {
        data[i] ^= key[i % MAX_KEY_LEN];
    }
}

// Decrypts the given data using the provided key
void decrypt_data(char *data, int datalen, char *key) {
    for (int i = 0; i < datalen; i++) {
        data[i] ^= key[i % MAX_KEY_LEN];
    }
}

// Main function
int main() {
    char key[MAX_KEY_LEN], data[MAX_DATA_LEN];
    int keylen, datalen;

    // Generate a random key
    generate_key(key, MAX_KEY_LEN);

    // Get the data to be encrypted
    printf("Enter the data to be encrypted: ");
    scanf("%s", data);
    datalen = strlen(data);

    // Encrypt the data
    encrypt_data(data, datalen, key);

    // Print the encrypted data
    printf("Encrypted data: %s\n", data);

    // Decrypt the data
    decrypt_data(data, datalen, key);

    // Print the decrypted data
    printf("Decrypted data: %s\n", data);

    return 0;
}