//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* encrypted_text) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    int i, j;

    for (i = 0, j = 0; i < text_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }

        encrypted_text[i] = text[i] ^ key[j];
    }

    encrypted_text[text_length] = '\0';
}

void decrypt(char* key, char* encrypted_text, char* decrypted_text) {
    int key_length = strlen(key);
    int encrypted_text_length = strlen(encrypted_text);
    int i, j;

    for (i = 0, j = 0; i < encrypted_text_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }

        decrypted_text[i] = encrypted_text[i] ^ key[j];
    }

    decrypted_text[encrypted_text_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH + 1];
    char decrypted_text[MAX_TEXT_LENGTH + 1];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text: ");
    scanf("%s", text);

    encrypt(key, text, encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    decrypt(key, encrypted_text, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}