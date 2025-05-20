//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define SHIFT 3

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        char ch = plaintext[i];
        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch + SHIFT - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch + SHIFT - 'a') % 26 + 'a';
        }
        // Keep other characters unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null terminate the string
}

void decrypt(char *ciphertext, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        char ch = ciphertext[i];
        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - SHIFT + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - SHIFT + 26 - 'a') % 26 + 'a';
        }
        // Keep other characters unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null terminate the string
}

void generateRandomString(char *str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0'; // Null terminate the string
}

void printMenu() {
    printf("\nCryptography Program Menu:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Generate and encrypt a random string\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char generatedString[MAX_LENGTH];
    
    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // consume newline character
                fgets(plaintext, MAX_LENGTH, stdin);
                plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline
                encrypt(plaintext, ciphertext);
                printf("Encrypted message: %s\n", ciphertext);
                break;
            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // consume newline character
                fgets(ciphertext, MAX_LENGTH, stdin);
                ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline
                decrypt(ciphertext, plaintext);
                printf("Decrypted message: %s\n", plaintext);
                break;
            case 3:
                printf("Generating random string...\n");
                generateRandomString(generatedString, 10); // generate string of length 10
                printf("Random String: %s\n", generatedString);
                encrypt(generatedString, ciphertext);
                printf("Encrypted Random String: %s\n", ciphertext);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}