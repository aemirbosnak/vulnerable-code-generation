//Falcon-180B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], char key[], int key_size) {
    int i, j, k;
    char encrypted_message[MAX_MESSAGE_SIZE];

    // Copy the message to the encrypted message buffer
    strcpy(encrypted_message, message);

    // Encrypt the message
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = toupper(encrypted_message[i]);
            j = (int) encrypted_message[i] + key_size % 26;
            if (isalpha(j)) {
                encrypted_message[i] = j;
            } else {
                encrypted_message[i] = 'A';
            }
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char encrypted_message[], char key[], int key_size) {
    int i, j, k;
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Copy the encrypted message to the decrypted message buffer
    strcpy(decrypted_message, encrypted_message);

    // Decrypt the message
    for (i = 0; i < strlen(decrypted_message); i++) {
        if (isalpha(decrypted_message[i])) {
            decrypted_message[i] = toupper(decrypted_message[i]);
            j = (int) decrypted_message[i] - key_size % 26;
            if (j < 65) {
                j = 65 + (26 - j % 26);
            }
            decrypted_message[i] = j;
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size;

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key (1-16 characters): ");
    scanf("%s", key);

    // Get the key size from the user
    printf("Enter the key size (1-16): ");
    scanf("%d", &key_size);

    // Encrypt the message
    encrypt(message, key, key_size);

    // Decrypt the encrypted message
    decrypt(message, key, key_size);

    return 0;
}