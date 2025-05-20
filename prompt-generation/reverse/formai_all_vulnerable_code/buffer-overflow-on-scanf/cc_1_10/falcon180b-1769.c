//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            } else if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            } else if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
    }
}

// Function to check if the string is a valid key
int isValidKey(char key[]) {
    int i;
    for (i = 0; key[i]!= '\0'; i++) {
        if (!isdigit(key[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char message[100], key[10];
    int choice, keyValue, i;

    // Get the message and key from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    printf("Enter the key (1-9): ");
    scanf("%s", key);

    // Validate the key
    if (!isValidKey(key)) {
        printf("Invalid key!\n");
        return 0;
    }

    // Encrypt the message
    keyValue = key[0] - '0';
    encrypt(message, keyValue);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Ask the user if they want to decrypt the message
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Decrypt the message
        decrypt(message, keyValue);

        // Display the decrypted message
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}