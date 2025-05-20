//Falcon-180B DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_PLAIN_TEXT_SIZE 1024
#define MAX_CIPHER_TEXT_SIZE (MAX_PLAIN_TEXT_SIZE + 1)

int main() {
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size;
    int plain_text_size;
    int cipher_text_size;

    // Get the plain text from user
    printf("Enter plain text: ");
    fgets(plain_text, MAX_PLAIN_TEXT_SIZE, stdin);

    // Remove newline character from plain text
    plain_text_size = strlen(plain_text) - 1;

    // Get the key from user
    printf("Enter key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // Remove newline character from key
    key_size = strlen(key) - 1;

    // Encrypt the plain text using the key
    int i, j, k;
    for (i = 0, j = 0; i < plain_text_size; i++) {
        if (isalpha(plain_text[i])) {
            if (isupper(plain_text[i])) {
                plain_text[i] = toupper(plain_text[i] + (int) key[j % key_size] - 65);
            } else {
                plain_text[i] = toupper(plain_text[i] + (int) key[j % key_size] - 97);
            }
            j++;
        } else {
            plain_text[i] = plain_text[i];
        }
    }

    // Add null terminator to plain text
    plain_text[plain_text_size] = '\0';

    // Get the cipher text size
    cipher_text_size = strlen(plain_text) + 1;

    // Copy the plain text to cipher text
    strcpy(cipher_text, plain_text);

    // Print the cipher text
    printf("Cipher text: %s\n", cipher_text);

    return 0;
}