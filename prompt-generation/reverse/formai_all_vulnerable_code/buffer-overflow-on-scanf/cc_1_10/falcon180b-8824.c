//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY "my_secret_key"
#define ARRAY_SIZE 26

// Function to encrypt the message
void encrypt(char message[100]) {
    int i, j;
    char key[ARRAY_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char encrypted_message[100];

    // Convert message to lowercase
    for (i = 0; message[i]!= '\0'; i++) {
        message[i] = tolower(message[i]);
    }

    // Encrypt message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            encrypted_message[i] = key[j];
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char message[100]) {
    int i, j;
    char key[ARRAY_SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char decrypted_message[100];

    // Convert message to lowercase
    for (i = 0; message[i]!= '\0'; i++) {
        message[i] = tolower(message[i]);
    }

    // Decrypt message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            decrypted_message[i] = key[j];
        } else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];

    // Get message from user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%[^\n]", message);

    // Encrypt message
    encrypt(message);

    // Decrypt message
    decrypt(message);

    return 0;
}