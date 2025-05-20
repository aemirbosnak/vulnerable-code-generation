//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
// Knuthian Modern Enciphering, in tribute to the [Father of Computer Science](https://en.wikipedia.org/wiki/Donald_Knuth)

// These imports are for a C compiler that supports C99 or later.
#include <stdio.h> // for printf, scanf
#include <stdlib.h> // for exit
#include <string.h> // for strcpy, strlen

// Define the alphabet for this cipher.
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

// Define the size of the alphabet.
#define ALPHABET_SIZE (int)(sizeof(ALPHABET) - 1)

// Define the key for this cipher.
#define KEY "SECRET"

// Define the key size.
#define KEY_SIZE (int)(strlen(KEY))

// Define the maximum size of the plaintext.
#define PLAINTEXT_SIZE 100

// Declare the functions used in this program.
void encrypt(char *plaintext, char *ciphertext);
void decrypt(char *ciphertext, char *plaintext);

// The main function.
int main(void) {
    // Declare the plaintext and ciphertext.
    char plaintext[PLAINTEXT_SIZE];
    char ciphertext[PLAINTEXT_SIZE];

    // Get the plaintext from the user.
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext.
    encrypt(plaintext, ciphertext);

    // Print the ciphertext.
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext.
    decrypt(ciphertext, plaintext);

    // Print the plaintext.
    printf("The plaintext is: %s\n", plaintext);

    // Exit the program.
    return 0;
}

// The encrypt function.
void encrypt(char *plaintext, char *ciphertext) {
    // Declare the variables used in this function.
    int i;
    int j;
    int k;

    // Loop through each character in the plaintext.
    for (i = 0; i < strlen(plaintext); i++) {
        // Find the index of the character in the alphabet.
        j = strchr(ALPHABET, plaintext[i]) - ALPHABET;

        // Shift the character by the key.
        k = (j + KEY[i % KEY_SIZE]) % ALPHABET_SIZE;

        // Replace the character in the ciphertext with the shifted character.
        ciphertext[i] = ALPHABET[k];
    }

    // Null-terminate the ciphertext.
    ciphertext[strlen(plaintext)] = '\0';
}

// The decrypt function.
void decrypt(char *ciphertext, char *plaintext) {
    // Declare the variables used in this function.
    int i;
    int j;
    int k;

    // Loop through each character in the ciphertext.
    for (i = 0; i < strlen(ciphertext); i++) {
        // Find the index of the character in the alphabet.
        j = strchr(ALPHABET, ciphertext[i]) - ALPHABET;

        // Shift the character by the key.
        k = (j - KEY[i % KEY_SIZE] + ALPHABET_SIZE) % ALPHABET_SIZE;

        // Replace the character in the plaintext with the shifted character.
        plaintext[i] = ALPHABET[k];
    }

    // Null-terminate the plaintext.
    plaintext[strlen(ciphertext)] = '\0';
}