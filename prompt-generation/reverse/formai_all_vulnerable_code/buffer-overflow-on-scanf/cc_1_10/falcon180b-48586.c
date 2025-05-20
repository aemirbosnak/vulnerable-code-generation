//Falcon-180B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

// Function to encrypt message using Caesar cipher
void encrypt(char* message, int key, char* encrypted_message) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (char)(message[i] + key - 65);
            } else {
                encrypted_message[i] = (char)(message[i] + key - 97);
            }
        } else {
            encrypted_message[i] = message[i];
        }
        i++;
    }
    encrypted_message[i] = '\0';
}

// Function to decrypt message using Caesar cipher
void decrypt(char* encrypted_message, int key, char* decrypted_message) {
    int i = 0;
    while (encrypted_message[i]!= '\0') {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = (char)(encrypted_message[i] - key - 65 + 26) % 26 + 65;
            } else {
                decrypted_message[i] = (char)(encrypted_message[i] - key - 97 + 26) % 26 + 97;
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
        i++;
    }
    decrypted_message[i] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];
    int key;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Get key from user
    printf("Enter key (1-256): ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}