//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000 // Maximum length of message to be encrypted/ decrypted
#define MAX_SHIFT 25 // Maximum shift for the Caesar cipher

// Function prototypes
char *caesar_encrypt(char *message, int shift);
char *caesar_decrypt(char *message, int shift);
char *vigenere_encrypt(char *message, char *key);
char *vigenere_decrypt(char *message, char *key);

int main() {
    char message[MAX_LENGTH] = {0};
    char key[MAX_LENGTH] = {0};
    int shift = 0;
    int choice = 0;

    // Display menu
    while (true) {
        printf("Choose an option:\n");
        printf("1. Encrypt message using Caesar cipher\n");
        printf("2. Decrypt message using Caesar cipher\n");
        printf("3. Encrypt message using Vigenere cipher\n");
        printf("4. Decrypt message using Vigenere cipher\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Get input from user
        if (choice >= 1 && choice <= 4) {
            printf("Enter message (maximum length %d): ", MAX_LENGTH);
            getchar(); // Clear input buffer
            fgets(message, MAX_LENGTH, stdin);
            message[strcspn(message, "\n")] = '\0'; // Remove newline character

            if (choice == 3 || choice == 4) {
                printf("Enter key (maximum length %d): ", MAX_LENGTH);
                fgets(key, MAX_LENGTH, stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline character
            }
            else {
                printf("Enter shift (maximum %d): ", MAX_SHIFT);
                scanf("%d", &shift);
            }
        }

        // Perform selected operation
        switch (choice) {
            case 1:
                printf("Encrypted message: %s\n", caesar_encrypt(message, shift));
                break;
            case 2:
                printf("Decrypted message: %s\n", caesar_decrypt(message, shift));
                break;
            case 3:
                printf("Encrypted message: %s\n", vigenere_encrypt(message, key));
                break;
            case 4:
                printf("Decrypted message: %s\n", vigenere_decrypt(message, key));
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Clear input buffer and message/ key arrays
        getchar();
        memset(message, 0, sizeof(message));
        memset(key, 0, sizeof(key));
    }

    return 0;
}

// Implementation of the Caesar cipher encryption algorithm
char *caesar_encrypt(char *message, int shift) {
    char *result = (char *) malloc(sizeof(char) * MAX_LENGTH);
    int i = 0;

    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = 'a' + (message[i] - 'a' + shift) % 26;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = 'A' + (message[i] - 'A' + shift) % 26;
        }
        else {
            result[i] = message[i];
        }

        i++;
    }

    result[i] = '\0';
    return result;
}

// Implementation of the Caesar cipher decryption algorithm
char *caesar_decrypt(char *message, int shift) {
    return caesar_encrypt(message, 26 - shift); // Decryption is just encryption with the reverse shift
}

// Implementation of the Vigenere cipher encryption algorithm
char *vigenere_encrypt(char *message, char *key) {
    char *result = (char *) malloc(sizeof(char) * MAX_LENGTH);
    int i = 0, j = 0, k = 0;

    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = 'a' + (message[i] - 'a' + key[j % strlen(key)] - 'a') % 26;
            j++;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = 'A' + (message[i] - 'A' + key[j % strlen(key)] - 'A') % 26;
            j++;
        }
        else {
            result[i] = message[i];
        }

        i++;
    }

    result[i] = '\0';
    return result;
}

// Implementation of the Vigenere cipher decryption algorithm
char *vigenere_decrypt(char *message, char *key) {
    char *result = (char *) malloc(sizeof(char) * MAX_LENGTH);
    int i = 0, j = 0, k = 0;

    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            result[i] = 'a' + (message[i] - 'a' - key[j % strlen(key)] + 'a') % 26;
            j++;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = 'A' + (message[i] - 'A' - key[j % strlen(key)] + 'A') % 26;
            j++;
        }
        else {
            result[i] = message[i];
        }

        i++;
    }

    result[i] = '\0';
    return result;
}