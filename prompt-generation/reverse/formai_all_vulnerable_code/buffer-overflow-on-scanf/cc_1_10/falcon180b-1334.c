//Falcon-180B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void generate_key(char *key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % charset_length];
    }
}

void encrypt(char *key, char *text, char *encrypted) {
    int key_length = strlen(key);

    for (int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);

        if (isalpha(c)) {
            int offset = (int)c - 65;
            encrypted[i] = key[(offset + (i % key_length)) % key_length];
        } else {
            encrypted[i] = text[i];
        }
    }
}

void decrypt(char *key, char *encrypted, char *decrypted) {
    int key_length = strlen(key);

    for (int i = 0; i < strlen(encrypted); i++) {
        char c = toupper(encrypted[i]);

        if (isalpha(c)) {
            int offset = (int)c - 65;
            int index = (offset - (i % key_length) + key_length) % key_length;

            if (index < 0) {
                index += key_length;
            }

            decrypted[i] = key[index];
        } else {
            decrypted[i] = encrypted[i];
        }
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted[MAX_TEXT_LENGTH];
    char decrypted[MAX_TEXT_LENGTH];

    printf("Enter a key: ");
    scanf("%s", key);

    printf("Enter text to encrypt: ");
    scanf("%s", text);

    generate_key(key, strlen(key));
    encrypt(key, text, encrypted);

    printf("Encrypted text: %s\n", encrypted);

    decrypt(key, encrypted, decrypted);

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}