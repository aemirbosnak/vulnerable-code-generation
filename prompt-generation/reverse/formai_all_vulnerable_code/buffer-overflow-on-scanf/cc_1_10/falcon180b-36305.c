//Falcon-180B DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1000

void encrypt(char *key, char *text) {
    int key_size = strlen(key);
    int text_size = strlen(text);
    char encrypted_text[MAX_TEXT_SIZE];
    int i, j, k;
    char key_index = 0;

    for (i = 0; i < text_size; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = tolower(text[i]);
            }
            encrypted_text[i] = key[key_index % key_size] ^ text[i];
            key_index++;
        } else {
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text[text_size] = '\0';

    printf("Encrypted text: %s\n", encrypted_text);
}

void decrypt(char *key, char *encrypted_text) {
    int key_size = strlen(key);
    int encrypted_text_size = strlen(encrypted_text);
    char decrypted_text[MAX_TEXT_SIZE];
    int i, j, k;
    char key_index = 0;

    for (i = 0; i < encrypted_text_size; i++) {
        if (isalpha(encrypted_text[i])) {
            if (isupper(encrypted_text[i])) {
                encrypted_text[i] = tolower(encrypted_text[i]);
            }
            decrypted_text[i] = encrypted_text[i] ^ key[key_index % key_size];
            key_index++;
        } else {
            decrypted_text[i] = encrypted_text[i];
        }
    }

    decrypted_text[encrypted_text_size] = '\0';

    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];

    printf("Enter encryption key: ");
    scanf("%s", key);

    printf("Enter text to encrypt: ");
    scanf("%s", text);

    encrypt(key, text);

    printf("\nEnter encrypted text: ");
    scanf("%s", text);

    decrypt(key, text);

    return 0;
}