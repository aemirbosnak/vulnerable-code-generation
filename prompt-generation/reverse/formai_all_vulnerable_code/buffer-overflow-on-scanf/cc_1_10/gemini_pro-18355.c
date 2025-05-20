//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <string.h>

// Caesar Cipher Function
char *caesar_cipher(char *plaintext, int shift) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Iterate over each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the current character and its ASCII value
        char c = plaintext[i];
        int ascii = (int)c;

        // Check if the character is a letter
        if (isalpha(c)) {
            // Shift the character by the given amount, wrapping around if necessary
            ascii += shift;
            if (ascii > (isalpha(c) ? 122 : 90)) {
                ascii -= 26;
            } else if (ascii < (isalpha(c) ? 97 : 65)) {
                ascii += 26;
            }
        }

        // Convert the shifted ASCII value back to a character
        ciphertext[i] = (char)ascii;
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Vigenere Cipher Function
char *vigenere_cipher(char *plaintext, char *key) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Iterate over each character in the plaintext
    int key_index = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the current character and its ASCII value
        char c = plaintext[i];
        int ascii = (int)c;

        // Check if the character is a letter
        if (isalpha(c)) {
            // Get the corresponding character from the key
            char key_char = key[key_index++];
            int key_ascii = (int)key_char;

            // Shift the character by the given amount, wrapping around if necessary
            ascii += key_ascii - (isalpha(c) ? 97 : 65);
            if (ascii > (isalpha(c) ? 122 : 90)) {
                ascii -= 26;
            } else if (ascii < (isalpha(c) ? 97 : 65)) {
                ascii += 26;
            }
        }

        // Convert the shifted ASCII value back to a character
        ciphertext[i] = (char)ascii;
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

int main() {
    // Get the plaintext message from the user
    printf("Enter the plaintext message: ");
    char plaintext[1024];
    fgets(plaintext, 1024, stdin);

    // Get the shift value for the Caesar cipher
    printf("Enter the shift value for the Caesar cipher (1-25): ");
    int shift;
    scanf("%d", &shift);

    // Encrypt the plaintext using the Caesar cipher
    char *caesar_ciphertext = caesar_cipher(plaintext, shift);

    // Print the Caesar ciphertext
    printf("Caesar Ciphertext: %s\n", caesar_ciphertext);

    // Get the key for the Vigenere cipher
    printf("Enter the key for the Vigenere cipher: ");
    char key[1024];
    fgets(key, 1024, stdin);

    // Encrypt the plaintext using the Vigenere cipher
    char *vigenere_ciphertext = vigenere_cipher(plaintext, key);

    // Print the Vigenere ciphertext
    printf("Vigenere Ciphertext: %s\n", vigenere_ciphertext);

    // Free the allocated memory
    free(caesar_ciphertext);
    free(vigenere_ciphertext);

    return 0;
}