//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
char* encrypt(char* message, int key) {
    char* encrypted = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Shift the character by the key amount
        encrypted[i] = (char)(((int)message[i] - 97 + key) % 26 + 97);
    }
    // Add the null terminator to the end of the encrypted string
    encrypted[strlen(message)] = '\0';
    return encrypted;
}

// Function to decrypt the message
char* decrypt(char* message, int key) {
    char* decrypted= (char*)malloc(sizeof(char) * (strlen(message) + 1));
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        // Shift the character back by the key amount
        decrypted[i] = (char)(((int)message[i] - 97 - key + 26) % 26 + 97);
    }
    // Add the null terminator to the end of the decrypted string
    decrypted[strlen(message)] = '\0';
    return decrypted;
}

int main() {
    char message[100];
    int key;

    // Get the message and the key from the user
    printf("Enter the message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Remove the newline character from the end of the message
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message using the given key
    char* encrypted = encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted);

    // Decrypt the message using the given key
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted Message: %s\n", decrypted);

    // Free the memory used by the encrypted and decrypted strings
    free(encrypted);
    free(decrypted);

    return 0;
}