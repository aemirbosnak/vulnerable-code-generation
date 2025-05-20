//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
// Donald Knuth-style Modern Encryption Example Program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define constants
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 100

// Define data types
typedef struct {
    char message[MAX_LENGTH];
    int message_length;
    char key[MAX_LENGTH];
    int key_length;
} EncryptedMessage;

// Define functions
void encrypt(EncryptedMessage *message) {
    for (int i = 0; i < message->message_length; i++) {
        message->message[i] = message->message[i] + message->key[i % message->key_length];
    }
}

void decrypt(EncryptedMessage *message) {
    for (int i = 0; i < message->message_length; i++) {
        message->message[i] = message->message[i] - message->key[i % message->key_length];
    }
}

// Main function
int main() {
    // Initialize variables
    EncryptedMessage message;
    char input[MAX_LENGTH];
    char key[MAX_LENGTH];
    int choice;

    // Get user input
    printf("Enter a message to encrypt or decrypt: ");
    fgets(input, MAX_LENGTH, stdin);
    printf("Enter a key: ");
    fgets(key, MAX_LENGTH, stdin);
    printf("Choose an action (1 for encryption, 2 for decryption): ");
    scanf("%d", &choice);

    // Process user input
    message.message_length = strlen(input);
    message.key_length = strlen(key);
    strcpy(message.message, input);
    strcpy(message.key, key);

    if (choice == 1) {
        encrypt(&message);
    } else if (choice == 2) {
        decrypt(&message);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    // Display output
    printf("The encrypted/decrypted message is: %s\n", message.message);

    return 0;
}