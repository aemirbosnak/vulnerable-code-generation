//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: curious
/*
 * Unique C Encryption Example Program in a Curious Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt a string
void encrypt(char *str) {
    // Generate a random key
    int key = rand() % 256;
    printf("Key: %d\n", key);

    // Encrypt the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] + key) % 256;
    }
}

// Function to decrypt a string
void decrypt(char *str) {
    // Generate a random key
    int key = rand() % 256;
    printf("Key: %d\n", key);

    // Decrypt the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = (str[i] - key + 256) % 256;
    }
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    // Encrypt the string
    encrypt(str);

    // Print the encrypted string
    printf("Encrypted string: %s\n", str);

    // Decrypt the string
    decrypt(str);

    // Print the decrypted string
    printf("Decrypted string: %s\n", str);

    return 0;
}