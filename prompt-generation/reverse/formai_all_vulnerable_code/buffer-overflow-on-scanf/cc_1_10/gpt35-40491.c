//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/*
    A simple encryption program that works
    by converting the message to its ASCII
    equivalent and performing mathematical
    operations on it. The message is then
    decrypted using the reverse mathematical
    operations.

    Developed by [Your Name]

    How it works:
    1. User inputs message to be encrypted.
    2. Program converts each character to its ASCII value.
    3. Program performs mathematical operations on ASCII values.
    4. Encrypted message is output.
    5. Program prompts user to decrypt message.
    6. User inputs encrypted message.
    7. Program performs reverse mathematical operations on ASCII values.
    8. Decrypted message is output.
*/

// Function to encrypt message
void encrypt(char message[], int key) {
    int i;
    int asciiValue;
    int newAsciiValue;
    char encryptedMessage[100];

    for (i = 0; i < strlen(message); i++) {
        asciiValue = (int) message[i];
        newAsciiValue = (asciiValue * key) - 7;
        encryptedMessage[i] = (char) newAsciiValue;        
    }

    printf("\nEncrypted message: %s\n", encryptedMessage);
}

// Function to decrypt message
void decrypt(char message[], int key) {
    int i;
    int asciiValue;
    int newAsciiValue;
    char decryptedMessage[100];

    for (i = 0; i < strlen(message); i++) {
        asciiValue = (int) message[i];
        newAsciiValue = (asciiValue + 7) / key;
        decryptedMessage[i] = (char) newAsciiValue;
    }

    printf("\nDecrypted message: %s\n", decryptedMessage);
}

// Main function
int main() {
    // Declare variables
    char message[100];
    int key;

    // Get input from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key);

    // Get input from user for decryption
    printf("Enter message to decrypt: ");
    scanf(" %[^\n]s", message);

    // Decrypt message
    decrypt(message, key);

    return 0;
}