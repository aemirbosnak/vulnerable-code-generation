//FormAI DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>

// Function to encrypt the message using the Caesar Cipher
char *encrypt(char *message, int key) {
    int i = 0;
    char ch;

    while (message[i] != '\0') {
        ch = message[i];

        // Ignore whitespace
        if (ch == ' ') {
            i++;
            continue;
        }

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') + key) % 26 + 'A';
        }

        // Encrypt lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') + key) % 26 + 'a';
        }

        // Update the message with the encrypted character
        message[i] = ch;
        i++;
    }

    return message;
}

int main() {
    char message[1000];
    int key;

    // Prompt user for message and encryption key
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Remove newline character from message
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] == '\n') {
            message[i] = '\0';
        }
        i++;
    }

    // Encrypt the message and print the result
    char *result = encrypt(message, key);
    printf("Encrypted message: %s\n", result);

    return 0;
}