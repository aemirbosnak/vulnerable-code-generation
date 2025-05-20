//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 256
#define KEY_LENGTH 128

void encryptDecrypt(char* input, char* key, char* output) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void getKey(char* key) {
    printf("Enter encryption key: ");
    fgets(key, KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character
}

int main() {
    char input[MAX_TEXT_LENGTH];
    char output[MAX_TEXT_LENGTH];
    char key[KEY_LENGTH];

    printf("Welcome to the Ultimate Shock Encryption System!\n");
    printf("You are about to enter a realm where your secrets will be scrambled!\n");

    // Get the plaintext input from the user
    printf("Please enter the text you want to encrypt (max 255 characters): ");
    fgets(input, MAX_TEXT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Get the key to encrypt the text
    getKey(key);

    // Encrypt the input using the provided key
    encryptDecrypt(input, key, output);

    // Display encrypted output
    printf("Encrypted text: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%02X ", (unsigned char) output[i]);
    }
    printf("\n");

    // Now decrypt to demonstrate the effectiveness of our system
    char decrypted[MAX_TEXT_LENGTH];
    encryptDecrypt(output, key, decrypted);

    // Display decrypted output
    printf("Decrypted text: %s\n", decrypted);

    printf("Prepare for the next level!\n");
    printf("===========================\n");
    printf("1. Encrypt again\n2. Exit\n");
    
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character after scanning
        
        if (choice == 1) {
            // Prompt for new text input
            printf("Please enter the text you want to encrypt (max 255 characters): ");
            fgets(input, MAX_TEXT_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character

            // Get the key to encrypt the text
            getKey(key);
            
            // Encrypt the input using the provided key
            encryptDecrypt(input, key, output);
            
            // Display encrypted output
            printf("Encrypted text: ");
            for (int i = 0; i < strlen(input); i++) {
                printf("%02X ", (unsigned char) output[i]);
            }
            printf("\n");
            
            // Decrypt to show that it works
            encryptDecrypt(output, key, decrypted);
            printf("Decrypted text: %s\n", decrypted);
        } else if (choice == 2) {
            printf("Exiting the shock zone! Stay secure!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}