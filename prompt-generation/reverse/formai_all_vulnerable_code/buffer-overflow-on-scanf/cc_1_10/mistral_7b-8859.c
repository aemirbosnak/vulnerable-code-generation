//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Exciting functions for encryption and decryption
void encryptText(char *plainText, char *encryptedText, char key) {
    int i;
    for (i = 0; plainText[i] != '\0'; i++) {
        if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            encryptedText[i] = ((plainText[i] - 'a' + key) % 26) + 'a';
        } else if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            encryptedText[i] = ((plainText[i] - 'A' + key) % 26) + 'A';
        } else {
            encryptedText[i] = plainText[i];
        }
    }
    encryptedText[i] = '\0';
}

void decryptText(char *encryptedText, char *decryptedText, char key) {
    int i;
    for (i = 0; encryptedText[i] != '\0'; i++) {
        if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
            decryptedText[i] = ((encryptedText[i] - 'a' - key + 26) % 26) + 'a';
        } else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
            decryptedText[i] = ((encryptedText[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            decryptedText[i] = encryptedText[i];
        }
    }
    decryptedText[i] = '\0';
}

// Main function to start the encryption and decryption process
int main() {
    char plainText[50], encryptedText[50], decryptedText[50];
    char key;

    // Exciting greeting message
    printf("\n\n*************************************************************\n");
    printf("* Welcome to the Exciting Cryptography Adventure!             *\n");
    printf("* Let's encrypt and decrypt some text with our amazing code! *\n");
    printf("*************************************************************\n");

    // Getting input for plain text and key from user
    printf("\nEnter the text you want to encrypt: ");
    fgets(plainText, sizeof(plainText), stdin);
    printf("Enter the encryption key (1-26): ");
    scanf("%d", &key);

    // Encrypting the plain text
    encryptText(plainText, encryptedText, key);

    // Exciting encryption message
    printf("\nYour text has been magically transformed into this: \n");
    printf("%s\n", encryptedText);

    // Decrypting the encrypted text
    decryptText(encryptedText, decryptedText, key);

    // Exciting decryption message
    printf("\nYour text has been successfully decrypted back to: \n");
    printf("%s\n", decryptedText);

    // Exciting goodbye message
    printf("\nYour text encryption and decryption adventure has come to an end!\n");
    printf("Press Enter to exit...\n");

    // Wait for user input before exiting
    getchar();
    return 0;
}