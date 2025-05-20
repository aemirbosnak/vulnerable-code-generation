//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_ENCRYPTED_LENGTH (MAX_MESSAGE_LENGTH + 1)

// Function to encrypt message using Caesar cipher
void caesar_encrypt(char *message, int key, char *encrypted_message) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (char) (message[i] + key - 65);
            } else {
                encrypted_message[i] = (char) (message[i] + key - 97);
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
}

// Function to decrypt message using Caesar cipher
void caesar_decrypt(char *encrypted_message, int key, char *decrypted_message) {
    int i;
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = (char) (encrypted_message[i] - key - 65);
            } else {
                decrypted_message[i] = (char) (encrypted_message[i] - key - 97);
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[i] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_ENCRYPTED_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int key;

    // Get message from user
    printf("Enter thy message to be encrypted: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Get encryption key from user
    printf("Enter thy encryption key (1-25): ");
    scanf("%d", &key);

    // Encrypt message
    caesar_encrypt(message, key, encrypted_message);

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    caesar_decrypt(encrypted_message, key, decrypted_message);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}