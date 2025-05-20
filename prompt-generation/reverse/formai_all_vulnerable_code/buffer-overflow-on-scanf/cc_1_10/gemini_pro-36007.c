//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The Caesar cipher shifts each character in the plaintext by a certain number of places
// in the alphabet. The amount of shift is known as the key.
int caesar_encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            // Check if the character is uppercase or lowercase
            if (isupper(plaintext[i])) {
                plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            } else {
                plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
    return 0;
}

// The Vigenere cipher is a generalization of the Caesar cipher, where the key is
// a string of characters. Each character in the key is used to shift the corresponding
// character in the plaintext.
int vigenere_encrypt(char *plaintext, char *key) {
    int len1 = strlen(plaintext);
    int len2 = strlen(key);
    // Create a new string to store the ciphertext
    char *ciphertext = malloc(len1 + 1);
    for (int i = 0, j = 0; i < len1; i++) {
        if (isalpha(plaintext[i])) {
            // Check if the character is uppercase or lowercase
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + key[j] - 'A') % 26) + 'A';
            } else {
                ciphertext[i] = ((plaintext[i] - 'a' + key[j] - 'a') % 26) + 'a';
            }
            j = (j + 1) % len2;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len1] = '\0';
    strcpy(plaintext, ciphertext);
    free(ciphertext);
    return 0;
}

// The main function takes the plaintext and the encryption algorithm as input and
// prints the ciphertext.
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Get the encryption algorithm from the user
    int algorithm;
    printf("Enter the encryption algorithm (1 for Caesar, 2 for Vigenere): ");
    scanf("%d", &algorithm);

    // Encrypt the plaintext using the specified algorithm
    if (algorithm == 1) {
        // Get the key for the Caesar cipher
        int key;
        printf("Enter the key for the Caesar cipher: ");
        scanf("%d", &key);

        // Encrypt the plaintext using the Caesar cipher
        caesar_encrypt(plaintext, key);
    } else if (algorithm == 2) {
        // Get the key for the Vigenere cipher
        char key[100];
        printf("Enter the key for the Vigenere cipher: ");
        scanf("%s", key);

        // Encrypt the plaintext using the Vigenere cipher
        vigenere_encrypt(plaintext, key);
    } else {
        printf("Invalid encryption algorithm");
        return 1;
    }

    // Print the ciphertext
    printf("The ciphertext is: %s\n", plaintext);

    return 0;
}