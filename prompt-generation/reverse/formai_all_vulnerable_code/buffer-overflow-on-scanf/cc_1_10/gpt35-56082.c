//FormAI DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to encrypt the original message
void encrypt(char message[], int key) {
    int i;
    char encrypted[100];

    // Loop through each character of the message
    for (i = 0; i < strlen(message); i++) {

        // Only shift alphabet characters
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = ((message[i] - 'A' + key) % 26) + 'A';
        } else {
            encrypted[i] = message[i];
        }
    }

    encrypted[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);
}

// Function to decrypt the encrypted message
void decrypt(char encrypted[], int key) {
    int i;
    char decrypted[100];

    // Loop through each character of the encrypted message
    for (i = 0; i < strlen(encrypted); i++) {

        // Only shift alphabet characters
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a' - key + 26) % 26) + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            decrypted[i] = encrypted[i];
        }
    }

    decrypted[i] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100], encrypted[100], decrypted[100];
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Remove the '\n' from the input buffer
    while (getchar() != '\n');

    encrypt(message, key);

    printf("\nEnter the message to be decrypted: ");
    fgets(encrypted, 100, stdin);

    // Remove the '\n' from the input buffer
    while (getchar() != '\n');

    printf("Enter the key: ");
    scanf("%d", &key);

    decrypt(encrypted, key);

    return 0;
}