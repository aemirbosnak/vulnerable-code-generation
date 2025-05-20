//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of the message and the key
#define MAX_LEN 100
#define MAX_KEY 10

// Function to encrypt the message using the key
void encrypt(char* msg, char* key) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);
    
    // Create a key stream
    char keystream[msg_len];
    int j = 0;
    for (int i = 0; i < msg_len; i++) {
        keystream[i] = key[j];
        j = (j + 1) % key_len;
    }
    
    // Encrypt the message using XOR cipher
    for (int i = 0; i < msg_len; i++) {
        msg[i] = msg[i] ^ keystream[i];
    }
}

// Function to decrypt the message using the key
void decrypt(char* msg, char* key) {
    encrypt(msg, key);
}

int main() {
    char message[MAX_LEN];
    char key[MAX_KEY];
    char choice;
    bool running = true;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_KEY, stdin);
    
    // Remove the newline character from the input strings
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    while (running) {
        printf("Choose an option:\n");
        printf("1. Encrypt the message\n");
        printf("2. Decrypt the message\n");
        printf("3. Exit\n");

        scanf(" %c", &choice);
        getchar(); // remove the newline character from stdin 

        switch (choice) {
            case '1':
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case '2':
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            case '3':
                running = false;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}