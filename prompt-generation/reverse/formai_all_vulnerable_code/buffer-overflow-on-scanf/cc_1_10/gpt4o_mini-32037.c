//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function prototypes
void encrypt(char *message, int key);
void decrypt(char *message, int key);
int getKey();

// Entry point of the program
int main() {
    char message[256];
    int choice, key;

    printf("Welcome to the decentralized encryption program!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline after the integer input
        
        switch (choice) {
            case 1:
                printf("Enter your message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                key = getKey();
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
                
            case 2:
                printf("Enter your message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                key = getKey();
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current = message[i];
        
        // Encrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            message[i] = (current - 'A' + key) % 26 + 'A';
        } 
        // Encrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            message[i] = (current - 'a' + key) % 26 + 'a';
        }
        // Non-alphabetical characters remain the same
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current = message[i];

        // Decrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            message[i] = (current - 'A' - key + 26) % 26 + 'A';
        } 
        // Decrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            message[i] = (current - 'a' - key + 26) % 26 + 'a';
        }
        // Non-alphabetical characters remain the same
    }
}

// Function to get the encryption key from user
int getKey() {
    int key;
    printf("Enter the encryption key (integer): ");
    scanf("%d", &key);
    return key % 26; // Ensuring the key is within 0-25
}