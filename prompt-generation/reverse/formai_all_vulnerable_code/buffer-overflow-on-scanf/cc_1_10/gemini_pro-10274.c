//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum size of the input string
#define MAX_STRING_SIZE 100

// Function to encrypt a string using the Caesar cipher
char* encryptCaesar(char* str, int shift) {
    char* encryptedStr = malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        // Get the current character and its ASCII value
        char c = str[i];
        int ascii = (int)c;

        // Shift the ASCII value by the specified amount
        ascii += shift;

        // Wrap around if necessary (i.e., if the ASCII value goes above 'z')
        if (ascii > 'z') {
            ascii -= 26;
        }

        // Convert the new ASCII value back to a character
        c = (char)ascii;

        // Store the encrypted character in the new string
        encryptedStr[i] = c;
    }

    // Add the null terminator to the end of the string
    encryptedStr[strlen(str)] = '\0';

    return encryptedStr;
}

// Function to decrypt a string using the Caesar cipher
char* decryptCaesar(char* str, int shift) {
    char* decryptedStr = malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        // Get the current character and its ASCII value
        char c = str[i];
        int ascii = (int)c;

        // Shift the ASCII value by the specified amount
        ascii -= shift;

        // Wrap around if necessary (i.e., if the ASCII value goes below 'a')
        if (ascii < 'a') {
            ascii += 26;
        }

        // Convert the new ASCII value back to a character
        c = (char)ascii;

        // Store the decrypted character in the new string
        decryptedStr[i] = c;
    }

    // Add the null terminator to the end of the string
    decryptedStr[strlen(str)] = '\0';

    return decryptedStr;
}

int main() {
    // Get the input string and shift amount from the user
    char str[MAX_STRING_SIZE];
    int shift;
    printf("Enter the string to encrypt: ");
    scanf("%s", str);
    printf("Enter the shift amount (1-25): ");
    scanf("%d", &shift);

    // Encrypt the input string using the Caesar cipher
    char* encryptedStr = encryptCaesar(str, shift);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encryptedStr);

    // Decrypt the encrypted string using the Caesar cipher
    char* decryptedStr = decryptCaesar(encryptedStr, shift);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decryptedStr);

    // Free the allocated memory
    free(encryptedStr);
    free(decryptedStr);

    return 0;
}