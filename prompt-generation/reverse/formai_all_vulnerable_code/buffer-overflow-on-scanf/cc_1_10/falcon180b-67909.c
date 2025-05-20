//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: calm
// This is a C Modern Encryption example program.
// The program will encrypt a plaintext message using a simple Caesar cipher.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAINTEXT_LENGTH 1000
#define MIN_KEY_VALUE 1
#define MAX_KEY_VALUE 25

// Function prototypes
void encrypt(char *plaintext, int key, char *ciphertext);
int main(int argc, char *argv[]);

// Main function
int main(int argc, char *argv[]) {
    char plaintext[MAX_PLAINTEXT_LENGTH];
    int key;

    // Prompt the user for a plaintext message
    printf("Enter a plaintext message (maximum %d characters):\n", MAX_PLAINTEXT_LENGTH);
    fgets(plaintext, MAX_PLAINTEXT_LENGTH, stdin);

    // Remove the newline character from the input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Prompt the user for a key value
    printf("Enter a key value (between %d and %d):\n", MIN_KEY_VALUE, MAX_KEY_VALUE);
    scanf("%d", &key);

    // Encrypt the plaintext message
    encrypt(plaintext, key, plaintext);

    // Print the ciphertext message
    printf("The ciphertext message is:\n%s\n", plaintext);

    return 0;
}

// Encryption function
void encrypt(char *plaintext, int key, char *ciphertext) {
    int i;

    // Loop through each character in the plaintext message
    for (i = 0; plaintext[i]!= '\0'; i++) {
        // Encrypt uppercase characters
        if (isupper(plaintext[i])) {
            ciphertext[i] = plaintext[i] + key - 65;
            if (ciphertext[i] > 90) {
                ciphertext[i] = ciphertext[i] - 26;
            }
        }
        // Encrypt lowercase characters
        else if (islower(plaintext[i])) {
            ciphertext[i] = plaintext[i] + key - 97;
            if (ciphertext[i] > 122) {
                ciphertext[i] = ciphertext[i] - 26;
            }
        }
        // Encrypt non-alphabetic characters
        else {
            ciphertext[i] = plaintext[i];
        }
    }

    // Add a null terminator to the ciphertext message
    ciphertext[i] = '\0';
}