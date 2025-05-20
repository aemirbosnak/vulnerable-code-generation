//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* result);
void decrypt(char* key, char* text, char* result);

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char result[MAX_TEXT_LENGTH];

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    encrypt(key, text, result);

    printf("Encrypted text: %s\n", result);

    printf("Enter the text to decrypt: ");
    scanf("%s", text);

    decrypt(key, text, result);

    printf("Decrypted text: %s\n", result);

    return 0;
}

void encrypt(char* key, char* text, char* result) {
    int i, j;
    char c;

    for (i = 0, j = 0; i < strlen(text); i++) {
        c = tolower(text[i]);
        if (isalpha(c)) {
            result[j++] = (c - 97 + (int)key[i % strlen(key)]) % 26 + 97;
        } else {
            result[j++] = c;
        }
    }

    result[j] = '\0';
}

void decrypt(char* key, char* text, char* result) {
    int i, j;
    char c;

    for (i = 0, j = 0; i < strlen(text); i++) {
        c = tolower(text[i]);
        if (isalpha(c)) {
            result[j++] = (c - (int)key[i % strlen(key)] + 26) % 26 + 97;
        } else {
            result[j++] = c;
        }
    }

    result[j] = '\0';
}