//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key)
{
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[j] = (message[i] + key - 65) % 26 + 65;
            } else {
                message[j] = (message[i] + key - 97) % 26 + 97;
            }
            j++;
        } else {
            message[j] = message[i];
            j++;
        }
    }
    message[j] = '\0';
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key)
{
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[j] = (message[i] - key - 65) % 26 + 65;
            } else {
                message[j] = (message[i] - key - 97) % 26 + 97;
            }
            j++;
        } else {
            message[j] = message[i];
            j++;
        }
    }
    message[j] = '\0';
}

// Function to generate a random key between 1 and 25
int generateKey()
{
    return rand() % 25 + 1;
}

int main()
{
    char message[1000];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate a random key
    key = generateKey();

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}