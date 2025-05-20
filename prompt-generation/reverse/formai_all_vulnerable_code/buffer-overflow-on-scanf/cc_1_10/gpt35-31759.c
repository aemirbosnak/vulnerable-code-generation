//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

void encrypt(char *message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            continue;
        }
        message[i] = message[i] + key;
    }
}

void decrypt(char *message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            continue;
        }
        message[i] = message[i] - key;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key;

    printf("Welcome to the Fun Encryption Program!\n");
    printf("Please enter the message you want to encrypt (max %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Please enter the encryption key (an integer value): ");
    scanf("%d", &key);

    printf("Encrypting message... Please wait.\n");
    encrypt(message, key);
    printf("Your encrypted message is: %s\n", message);

    printf("Would you like to decrypt the message? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y') {
        printf("Please enter the decryption key: ");
        int decryption_key;
        scanf("%d", &decryption_key);

        printf("Decrypting message... Please wait.\n");
        decrypt(message, decryption_key);
        printf("Your decrypted message is: %s\n", message);
    }

    printf("Thank you for using the Fun Encryption Program! Goodbye.\n");

    return 0;
}