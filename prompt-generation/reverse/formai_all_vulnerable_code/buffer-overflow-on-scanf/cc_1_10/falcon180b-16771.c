//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Get the text to encrypt from the user
    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    // Encrypt the text using the key
    int key_index = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                encrypted_text[i] = 'A' + ((text[i] - 'A' + key_index) % 26);
            } else {
                encrypted_text[i] = 'a' + ((text[i] - 'a' + key_index) % 26);
            }
        } else {
            encrypted_text[i] = text[i];
        }
        key_index = (key_index + 1) % strlen(key);
    }

    // Display the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Decrypt the encrypted text using the key
    key_index = 0;
    for (int i = 0; i < strlen(encrypted_text); i++) {
        if (isalpha(encrypted_text[i])) {
            if (isupper(encrypted_text[i])) {
                decrypted_text[i] = 'A' + (((encrypted_text[i] - 'A' - key_index + 26) % 26) + 1);
            } else {
                decrypted_text[i] = 'a' + (((encrypted_text[i] - 'a' - key_index + 26) % 26) + 1);
            }
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
        key_index = (key_index + 1) % strlen(key);
    }

    // Display the decrypted text
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}