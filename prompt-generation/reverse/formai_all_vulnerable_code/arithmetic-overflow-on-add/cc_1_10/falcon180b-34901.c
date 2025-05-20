//Falcon-180B DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;
    char encrypted_message[100];
    encrypted_message[0] = '\0';

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Shift the character by the key value
            j = (((message[i] - 'A') + key) % SIZE) + 'A';

            // Append the shifted character to the encrypted message
            strcat(encrypted_message, &j);
        } else {
            // Append non-alphabetic characters as is
            strcat(encrypted_message, &message[i]);
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;
    char decrypted_message[100];
    decrypted_message[0] = '\0';

    // Loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            // Convert the character to uppercase
            message[i] = toupper(message[i]);

            // Shift the character back by the key value
            j = (((message[i] - 'A') - key + SIZE) % SIZE) + 'A';

            // Append the shifted character to the decrypted message
            strcat(decrypted_message, &j);
        } else {
            // Append non-alphabetic characters as is
            strcat(decrypted_message, &message[i]);
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}