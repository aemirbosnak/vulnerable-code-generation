//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        // Check if character is uppercase
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
        // Check if character is lowercase
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key) {
    // Use the negative key for decryption
    encrypt(message, 26 - (key % 26));
}

int main() {
    char message[MAX];
    int key, choice;

    printf("Welcome to the Simple Caesar Cipher Program!\n");
    printf("Please enter your message (max %d characters): ", MAX - 1);
    fgets(message, MAX, stdin);
    
    // Remove newline character if present
    message[strcspn(message, "\n")] = 0;

    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    // Ensure that key is within valid range
    while (key < 1 || key > 25) {
        printf("Invalid key! Please enter a key between 1 and 25: ");
        scanf("%d", &key);
    }

    printf("\nChoose an option: \n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted Message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted Message: %s\n", message);
            break;
        default:
            printf("Invalid choice! Please select 1 or 2.\n");
            break;
    }

    return 0;
}