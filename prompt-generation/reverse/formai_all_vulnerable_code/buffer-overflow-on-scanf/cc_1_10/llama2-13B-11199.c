//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_KEY_LENGTH 20

void encrypt_message(char *message, char *key);
void decrypt_message(char *message, char *key);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    printf("Welcome to the Gratitude Encryption Program!\n");
    printf("Please enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Please enter a key to use for encryption: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    choice = 0;
    while (choice != 1 && choice != 2) {
        printf("Invalid input. Please enter a valid choice (1 for encryption, 2 for decryption): ");
        scanf("%d", &choice);
    }

    if (choice == 1) {
        encrypt_message(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt_message(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}

void encrypt_message(char *message, char *key) {
    int i, j, k;
    char temp;

    for (i = 0; i < strlen(message); i++) {
        temp = message[i];
        for (j = 0; j < strlen(key); j++) {
            k = (temp + key[j]) % 26;
            temp = (k + 65) % 26;
            message[i] = temp;
        }
    }
}

void decrypt_message(char *message, char *key) {
    int i, j, k;
    char temp;

    for (i = 0; i < strlen(message); i++) {
        temp = message[i];
        for (j = 0; j < strlen(key); j++) {
            k = (temp - key[j]) % 26;
            temp = (k + 65) % 26;
            message[i] = temp;
        }
    }
}