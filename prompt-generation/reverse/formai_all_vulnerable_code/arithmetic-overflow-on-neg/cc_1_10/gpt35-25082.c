//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted = (char*) malloc(len + 1);

    for(int i = 0; i < len; i++) {
        // Shift the letter by the given key
        char c = message[i];
        if(c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + key) % 26 + 'A';
        } else if(c >= 'a' && c <= 'z') {
            c = ((c - 'a') + key) % 26 + 'a';
        }
        encrypted[i] = c;
    }
    encrypted[len] = '\0';

    return encrypted;
}

char* decrypt(char* message, int key) {
    // Decrypting is just encrypting by the negative key
    return encrypt(message, -key);
}

int main(void) {
    // Read input from user
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    int key;
    printf("Enter a key value (int): ");
    scanf("%d", &key);

    // Remove the newline character that fgets puts at the end of the string
    int len = strlen(message);
    if(message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Encrypt the message and print the result
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message and print the result
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    // Free the allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}