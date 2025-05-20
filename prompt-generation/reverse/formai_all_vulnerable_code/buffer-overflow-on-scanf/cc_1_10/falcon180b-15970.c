//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_TEXT_SIZE 10000

void generateKey(char *key, int keySize) {
    for (int i = 0; i < keySize; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[keySize] = '\0';
}

void encrypt(char *text, int textSize, char *key, int keySize) {
    for (int i = 0; i < textSize; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            int k = tolower(key[i % keySize]) - 'a';
            char e = (c + k) % 26 + 'a';
            text[i] = e;
        }
    }
}

void decrypt(char *text, int textSize, char *key, int keySize) {
    for (int i = 0; i < textSize; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            int k = tolower(key[i % keySize]) - 'a';
            char e = (c - k + 26) % 26 + 'a';
            text[i] = e;
        }
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    printf("Enter the key: ");
    scanf("%s", key);

    int textSize = strlen(text);
    int keySize = strlen(key);

    if (textSize > MAX_TEXT_SIZE || keySize > MAX_KEY_SIZE) {
        printf("Error: Text or key size is too large.\n");
        return 0;
    }

    encrypt(text, textSize, key, keySize);

    printf("Encrypted text: %s\n", text);

    decrypt(text, textSize, key, keySize);

    printf("Decrypted text: %s\n", text);

    return 0;
}