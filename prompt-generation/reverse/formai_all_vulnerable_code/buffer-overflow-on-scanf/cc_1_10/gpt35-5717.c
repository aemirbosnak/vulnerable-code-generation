//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define MAX_KEY_LEN 16

typedef struct {
    char message[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
} Message;

void encrypt(Message *msg) {
    int i, j = 0;
    char c;

    // Get the length of the key and message
    int key_len = strlen(msg->key);
    int msg_len = strlen(msg->message);

    // Encrypt the message using the Vigenere cipher
    for (i = 0; i < msg_len; i++) {
        // Ignore spaces and non-alphabetic characters
        if (msg->message[i] == ' ' || !isalpha(msg->message[i])) {
            continue;
        }

        c = ((msg->message[i] - 'a') + (msg->key[j] - 'a')) % 26;
        msg->message[i] = c + 'a';

        // Loop through the key
        j = (j + 1) % key_len;
    }
}

void decrypt(Message *msg) {
    int i, j = 0;
    char c;

    // Get the length of the key and message
    int key_len = strlen(msg->key);
    int msg_len = strlen(msg->message);

    // Decrypt the message using the Vigenere cipher
    for (i = 0; i < msg_len; i++) {
        // Ignore spaces and non-alphabetic characters
        if (msg->message[i] == ' ' || !isalpha(msg->message[i])) {
            continue;
        }

        c = ((msg->message[i] - 'a') - (msg->key[j] - 'a') + 26) % 26;
        msg->message[i] = c + 'a';

        // Loop through the key
        j = (j + 1) % key_len;
    }
}

int main() {
    Message msg;
    int choice;

    // Get the message and key
    printf("Enter your message: ");
    fgets(msg.message, MAX_MSG_LEN, stdin);
    msg.message[strcspn(msg.message, "\n")] = '\0';

    printf("Enter your key: ");
    fgets(msg.key, MAX_KEY_LEN, stdin);
    msg.key[strcspn(msg.key, "\n")] = '\0';

    // Ask the user whether to encrypt or decrypt
    printf("\nWhat would you like to do?\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Encrypt or decrypt the message based on user choice
    switch (choice) {
        case 1:
            encrypt(&msg);
            printf("\nEncrypted message: %s\n", msg.message);
            break;

        case 2:
            decrypt(&msg);
            printf("\nDecrypted message: %s\n", msg.message);
            break;

        default:
            printf("\nInvalid choice\n");
            return 1;
    }

    return 0;
}