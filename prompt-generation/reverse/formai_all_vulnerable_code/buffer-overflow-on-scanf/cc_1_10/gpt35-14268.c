//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LEN 16

void encrypt(char *message, char *key) {
    srand(time(NULL));
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] ^ key[i % KEY_LEN];
    }
}

void decrypt(char *message, char *key) {
    encrypt(message, key);
}

int main() {
    char message[1000];
    char key[KEY_LEN];
    printf("Welcome to the Super Encrypting Program!\n");
    printf("Please enter the message you wish to encrypt:\n");
    scanf("%s", message);

    int choice;
    printf("Choose from the following menu:\n");
    printf("1. Enter a custom key.\n");
    printf("2. Make me a sandwich.\n");
    printf("3. Random key.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a %d-character key: ", KEY_LEN);
            scanf("%s", key);
            break;
        case 2:
            printf("I'm sorry, I cannot make sandwiches yet.\n");
            printf("Please enter a %d-character key: ", KEY_LEN);
            scanf("%s", key);
            break;
        case 3:
            printf("Generating a random key...\n");
            for (int i = 0; i < KEY_LEN; i++) {
                key[i] = rand() % 256;
            }
            break;
        default:
            printf("Invalid choice. Aborting...\n");
            return 1;
    }

    printf("Encrypting message...\n");
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Decrypting message...\n");
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}