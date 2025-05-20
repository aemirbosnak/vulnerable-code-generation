//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Define the encryption function
void encrypt(char *message) {
    int i = 0;
    int j = 0;
    char buffer[strlen(message)];

    // Copy the message to a buffer
    strcpy(buffer, message);

    // Encrypt the message
    for (i = 0; i < strlen(message); i++) {
        char c = buffer[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 65) + 97; // Shift uppercase letters to lowercase
            }
            c = c + ((int)KEY[j] - 97); // Encrypt using the key
            j++;
            if (j == strlen(KEY)) {
                j = 0;
            }
        }
        buffer[i] = c;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", buffer);
}

// Define the decryption function
void decrypt(char *message) {
    int i = 0;
    int j = 0;
    char buffer[strlen(message)];

    // Copy the message to a buffer
    strcpy(buffer, message);

    // Decrypt the message
    for (i = 0; i < strlen(message); i++) {
        char c = buffer[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                c = (c - 97) + 65; // Shift lowercase letters to uppercase
            }
            c = c - ((int)KEY[j] - 97); // Decrypt using the key
            j++;
            if (j == strlen(KEY)) {
                j = 0;
            }
        }
        buffer[i] = c;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", buffer);
}

// Define the main function
int main() {
    char message[100];

    // Get the message from the user
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the message
    decrypt(message);

    return 0;
}