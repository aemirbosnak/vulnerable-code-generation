//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: recursive
/*
 * Recursive encryption program in C
 *
 * Usage: ./encrypt <text> <key>
 *
 * Encrypts the given text with the given key using a recursive algorithm.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the encryption function
void encrypt(char *text, char *key, int n) {
    // Base case: If the text is empty, return
    if (strlen(text) == 0) {
        return;
    }

    // Encrypt the first character of the text
    int cipher = text[0] + key[n];

    // If the cipher is greater than 126, wrap it around
    if (cipher > 126) {
        cipher -= 126;
    }

    // Print the encrypted character
    printf("%c", cipher);

    // Recursively encrypt the rest of the text
    encrypt(text + 1, key, n);
}

int main(int argc, char **argv) {
    // Check if the correct number of arguments was given
    if (argc != 3) {
        printf("Usage: ./encrypt <text> <key>\n");
        return 1;
    }

    // Get the text and key from the command line arguments
    char *text = argv[1];
    char *key = argv[2];

    // Encrypt the text with the key
    encrypt(text, key, 0);

    return 0;
}