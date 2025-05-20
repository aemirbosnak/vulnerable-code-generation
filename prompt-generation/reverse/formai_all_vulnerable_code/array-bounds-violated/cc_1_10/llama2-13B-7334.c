//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: introspective
// The Encryption of Secrets, A Tale of Introspection

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

// The Encryption Function
void encrypt(char *message, char *key) {
    int i, j, k;
    char c, d, e;

    // Reflect the message on itself
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        message[i] = message[strlen(message) - i - 1];
        message[strlen(message) - i - 1] = c;
    }

    // Shift the message by the key
    for (i = 0; i < strlen(key); i++) {
        c = key[i];
        for (j = 0; j < strlen(message); j++) {
            d = message[j];
            message[j] = (d + c) % 26;
        }
    }

    // Mix the message with itself
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        for (j = 0; j < strlen(message); j++) {
            d = message[j];
            e = message[strlen(message) - j - 1];
            message[i] = (c + d + e) % 26;
        }
    }
}

// The Decryption Function
void decrypt(char *message, char *key) {
    int i, j, k;
    char c, d, e;

    // Reflect the message on itself
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        message[i] = message[strlen(message) - i - 1];
        message[strlen(message) - i - 1] = c;
    }

    // Shift the message by the key (in reverse)
    for (i = 0; i < strlen(key); i++) {
        c = key[i];
        for (j = strlen(message) - 1; j >= 0; j--) {
            d = message[j];
            message[j] = (d - c) % 26;
        }
    }

    // Unmix the message
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        for (j = 0; j < strlen(message); j++) {
            d = message[j];
            e = message[strlen(message) - j - 1];
            message[i] = (c + d + e) % 26;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    // Ask the user for the message and key
    printf("Enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strlen(message) - 1] = '\0';

    printf("Enter a key (max %d characters): ", MAX_KEY_LENGTH);
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strlen(key) - 1] = '\0';

    // Ask the user to choose the operation (encryption or decryption)
    printf("Do you want to encrypt or decrypt the message? (e/d): ");
    scanf("%d", &choice);

    // Perform the operation
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}