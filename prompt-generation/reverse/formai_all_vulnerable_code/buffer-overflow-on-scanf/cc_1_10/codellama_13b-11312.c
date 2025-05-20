//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define the encryption and decryption functions
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    // prompt the user for the message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    // prompt the user for the encryption shift
    int shift;
    printf("Enter the encryption shift (0-25): ");
    scanf("%d", &shift);

    // encrypt the message
    encrypt(message, shift);

    // display the encrypted message
    printf("Encrypted message: %s\n", message);

    // prompt the user for the decryption shift
    printf("Enter the decryption shift (0-25): ");
    scanf("%d", &shift);

    // decrypt the message
    decrypt(message, shift);

    // display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift) {
    // iterate through each character in the message
    for (int i = 0; message[i] != '\0'; i++) {
        // encrypt the character
        message[i] = (message[i] + shift) % 256;
    }
}

void decrypt(char *message, int shift) {
    // iterate through each character in the message
    for (int i = 0; message[i] != '\0'; i++) {
        // decrypt the character
        message[i] = (message[i] - shift) % 256;
    }
}