//Falcon-180B DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using a key
void encrypt(char message[], char key[]) {
    int i, j, k;
    int key_length = strlen(key);
    int message_length = strlen(message);

    // Check if key is valid
    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return;
    }

    // Repeat key to match message length
    while (key_length < message_length) {
        strcat(key, key);
        key_length += strlen(key);
    }

    // Encrypt message
    for (i = 0; i < message_length; i++) {
        message[i] = message[i] + key[i % key_length];
    }
}

// Function to decrypt the message using a key
void decrypt(char message[], char key[]) {
    int i, j, k;
    int key_length = strlen(key);
    int message_length = strlen(message);

    // Check if key is valid
    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return;
    }

    // Repeat key to match message length
    while (key_length < message_length) {
        strcat(key, key);
        key_length += strlen(key);
    }

    // Decrypt message
    for (i = 0; i < message_length; i++) {
        message[i] = message[i] - key[i % key_length];
    }
}

// Function to display a menu
void menu() {
    printf("Encryption/Decryption Menu\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        printf("Enter message to %s: ", choice == 1? "encrypt" : "decrypt");
        scanf("%s", message);
        printf("Enter key: ");
        scanf("%s", key);

        if (choice == 1) {
            encrypt(message, key);
        } else if (choice == 2) {
            decrypt(message, key);
        }

        printf("\n%s: %s\n", choice == 1? "Encrypted" : "Decrypted", message);
    } while (choice!= 3);

    return 0;
}