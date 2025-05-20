//Falcon-180B DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1024

void encrypt(char *key, char *text) {
    int i, j, k, key_length = strlen(key);
    char encrypted_text[MAX_TEXT_LENGTH];
    memset(encrypted_text, '\0', MAX_TEXT_LENGTH);

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                encrypted_text[j++] = (char) ((int) text[i] + (int) key[k % key_length]);
            } else {
                encrypted_text[j++] = (char) ((int) text[i] + (int) key[k % key_length] - 32);
            }
            k++;
        } else {
            encrypted_text[j++] = text[i];
        }
    }

    printf("Encrypted Text: %s\n", encrypted_text);
}

void decrypt(char *key, char *text) {
    int i, j, k, key_length = strlen(key);
    char decrypted_text[MAX_TEXT_LENGTH];
    memset(decrypted_text, '\0', MAX_TEXT_LENGTH);

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                decrypted_text[j++] = (char) ((int) text[i] - (int) key[k % key_length]);
            } else {
                decrypted_text[j++] = (char) ((int) text[i] - (int) key[k % key_length] + 32);
            }
            k++;
        } else {
            decrypted_text[j++] = text[i];
        }
    }

    printf("Decrypted Text: %s\n", decrypted_text);
}

int main() {
    char key[MAX_KEY_LENGTH], text[MAX_TEXT_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    encrypt(key, text);
    decrypt(key, text);

    return 0;
}