//Falcon-180B DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char *key, char *text) {
    // Initialize the encryption key
    int key_length = strlen(key);
    int key_index = 0;
    int text_index = 0;
    int text_length = strlen(text);
    char encrypted_text[MAX_TEXT_LENGTH];

    // Encrypt the text using the key
    while (text_index < text_length) {
        if (isalpha(text[text_index])) {
            if (isupper(text[text_index])) {
                encrypted_text[text_index] = key[key_index] + 'A';
            } else {
                encrypted_text[text_index] = key[key_index] + 'a';
            }
        } else {
            encrypted_text[text_index] = text[text_index];
        }

        key_index = (key_index + 1) % key_length;
        text_index++;
    }

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];

    // Get the encryption key and text from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    // Encrypt the text using the key
    encrypt(key, text);

    return 0;
}