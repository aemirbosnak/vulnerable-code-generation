//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int key_index = 0;
    for (int i = 0; i < strlen(message); i++) {
        char current_char = toupper(message[i]);
        if (isalpha(current_char)) {
            int shift = (key[key_index] - 'A' + 13) % 26;
            current_char = current_char + shift;
            if (current_char > 'Z') {
                current_char = current_char - 26;
            }
        }
        printf("%c", current_char);
        key_index = (key_index + 1) % strlen(key);
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key) {
    int key_index = 0;
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char current_char = toupper(encrypted_message[i]);
        if (isalpha(current_char)) {
            int shift = (key[key_index] - 'A' + 13) % 26;
            current_char = current_char - shift;
            if (current_char < 'A') {
                current_char = current_char + 26;
            }
        }
        printf("%c", current_char);
        key_index = (key_index + 1) % strlen(key);
    }
}

int main() {
    // Get the message and key from the user
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);
    printf("Enter the key to encrypt the message: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);
    printf("\nEncrypted message: ");

    // Decrypt the message
    decrypt(message, key);
    printf("\nDecrypted message: ");

    return 0;
}