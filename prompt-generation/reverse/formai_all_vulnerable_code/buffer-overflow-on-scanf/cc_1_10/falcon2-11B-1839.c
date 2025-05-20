//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 100
#define KEY_SIZE 26

// Helper function to convert a character to uppercase
char to_upper(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

// Encryption function
void encrypt(char* message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = to_upper(message[i]) + key;
        if (message[i] > 'Z')
            message[i] -= KEY_SIZE;
    }
}

// Decryption function
void decrypt(char* message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = to_upper(message[i]) - key;
        if (message[i] < 'A')
            message[i] += KEY_SIZE;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key;

    // Get the message from the user
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Get the key from the user
    printf("Enter a key (1-26): ");
    scanf("%d", &key);

    if (key < 1 || key > KEY_SIZE) {
        printf("Invalid key\n");
        return 1;
    }

    // Encrypt the message
    printf("Encrypted message: ");
    encrypt(message, key);
    printf("%s\n", message);

    // Decrypt the message
    printf("Decrypted message: ");
    decrypt(message, key);
    printf("%s\n", message);

    return 0;
}