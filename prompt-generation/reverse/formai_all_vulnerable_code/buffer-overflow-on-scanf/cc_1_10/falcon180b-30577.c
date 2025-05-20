//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 100

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

// Function to encrypt a message using a key
void encrypt_message(char* message, char* key, char* encrypted_message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = toupper(message[i] + (int) key[i % MAX_KEY_LENGTH] - 65);
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';
}

// Function to decrypt a message using a key
void decrypt_message(char* encrypted_message, char* key, char* decrypted_message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = toupper(encrypted_message[i] - (int) key[i % MAX_KEY_LENGTH] + 65);
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';
}

int main() {
    char message[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH], encrypted_message[MAX_TEXT_LENGTH], decrypted_message[MAX_TEXT_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    generate_key(key);
    encrypt_message(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    decrypt_message(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}