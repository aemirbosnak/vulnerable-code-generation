//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_DATA_LENGTH 1000

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

// Function to encrypt data using the key
void encrypt(char* data, char* key) {
    int i, j;
    char encrypted_data[MAX_DATA_LENGTH];
    encrypted_data[0] = '\0';
    for (i = 0; i < strlen(data); i++) {
        encrypted_data[i] = 'a' + (data[i] + key[i % strlen(key)] - 'a') % 26;
    }
    encrypted_data[strlen(data)] = '\0';
    printf("Encrypted data: %s\n", encrypted_data);
}

// Function to decrypt data using the key
void decrypt(char* encrypted_data, char* key) {
    int i, j;
    char decrypted_data[MAX_DATA_LENGTH];
    decrypted_data[0] = '\0';
    for (i = 0; i < strlen(encrypted_data); i++) {
        decrypted_data[i] = 'a' + (encrypted_data[i] - key[i % strlen(key)] + 26) % 26;
    }
    decrypted_data[strlen(encrypted_data)] = '\0';
    printf("Decrypted data: %s\n", decrypted_data);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];

    // Generate a random key
    generate_key(key);

    // Get input data from user
    printf("Enter data to encrypt: ");
    scanf("%s", data);

    // Encrypt the data using the key
    encrypt(data, key);

    // Decrypt the encrypted data using the key
    decrypt(data, key);

    return 0;
}