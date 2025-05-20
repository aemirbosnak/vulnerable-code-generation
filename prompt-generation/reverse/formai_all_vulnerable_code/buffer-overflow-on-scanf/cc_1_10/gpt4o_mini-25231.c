//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *encrypted_message, int key) {
    int i;
    // Encrypt each character using the key
    for (i = 0; i < strlen(message); i++) {
        // Wrap around using modulo for non-printable characters
        encrypted_message[i] = message[i] + key;
    }
    encrypted_message[i] = '\0'; // Null-terminate the encrypted string
}

void decrypt(char *encrypted_message, char *decrypted_message, int key) {
    int i;
    // Decrypt each character using the key
    for (i = 0; i < strlen(encrypted_message); i++) {
        // Wrap around using modulo for non-printable characters
        decrypted_message[i] = encrypted_message[i] - key;
    }
    decrypted_message[i] = '\0'; // Null-terminate the decrypted string
}

void get_input(char *buffer, int size) {
    printf("Enter your message: ");
    fgets(buffer, size, stdin); // Get user input
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the trailing newline
}

int main() {
    char message[256]; // Buffer for original message
    char encrypted_message[256]; // Buffer for encrypted message
    char decrypted_message[256]; // Buffer for decrypted message
    int key;

    // Get user input
    get_input(message, sizeof(message));

    // Get encryption key from user
    printf("Enter encryption key (integer): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, encrypted_message, key);
    printf("Encrypted Message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(encrypted_message, decrypted_message, key);
    printf("Decrypted Message: %s\n", decrypted_message);

    // Validation of encryption and decryption
    if (strcmp(message, decrypted_message) == 0) {
        printf("Success! The original message and decrypted message match.\n");
    } else {
        printf("Error! The decrypted message does not match the original.\n");
    }

    // Additional functionality: Print character values
    printf("\nCharacter Values Before Encryption:\n");
    for (int i = 0; i < strlen(message); i++) {
        printf("'%c' : %d\n", message[i], message[i]);
    }

    printf("\nCharacter Values After Encryption:\n");
    for (int i = 0; i < strlen(encrypted_message); i++) {
        printf("'%c' : %d\n", encrypted_message[i], encrypted_message[i]);
    }

    printf("\nCharacter Values After Decryption:\n");
    for (int i = 0; i < strlen(decrypted_message); i++) {
        printf("'%c' : %d\n", decrypted_message[i], decrypted_message[i]);
    }

    return 0;
}