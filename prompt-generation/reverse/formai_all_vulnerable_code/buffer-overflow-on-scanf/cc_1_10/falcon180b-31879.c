//Falcon-180B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate encryption key
void generate_key(char* key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt message
void encrypt(char* message, int message_size, char* key) {
    int i, j;
    for (i = 0; i < message_size; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < message_size; j++) {
            message[i + j] = toupper(message[i + j]) ^ key[j % KEY_SIZE];
        }
    }
}

// Function to decrypt message
void decrypt(char* message, int message_size, char* key) {
    int i, j;
    for (i = 0; i < message_size; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < message_size; j++) {
            message[i + j] = message[i + j] ^ key[j % KEY_SIZE];
        }
    }
}

// Function to display menu
void menu() {
    printf("\n");
    printf("Encryption Menu\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("3. Exit\n");
    printf("\n");
}

// Main function
int main() {
    char message[1000], key[KEY_SIZE];
    int message_size, choice;

    // Seed random number generator
    srand(time(NULL));

    // Generate encryption key
    generate_key(key, KEY_SIZE);

    // Display menu
    menu();

    // Get user choice
    scanf("%d", &choice);

    // Get message to encrypt/decrypt
    printf("Enter message to %s: ", choice == 1? "encrypt" : "decrypt");
    fgets(message, 1000, stdin);
    message_size = strlen(message) - 1;

    // Encrypt/decrypt message
    if (choice == 1) {
        encrypt(message, message_size, key);
        printf("Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, message_size, key);
        printf("Decrypted Message: %s\n", message);
    } else {
        printf("Exiting...\n");
    }

    return 0;
}