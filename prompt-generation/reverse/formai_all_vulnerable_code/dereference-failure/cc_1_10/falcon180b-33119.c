//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1000
#define MAX_ENCRYPTED_TEXT_LENGTH (MAX_TEXT_LENGTH * 2)

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[i] = '\0';
}

void encrypt(char* text, char* key, char* encrypted_text) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            k = c - 'A';
            if (k < 0) {
                k += 26;
            }
            encrypted_text[j++] = key[k];
        } else {
            encrypted_text[j++] = c;
        }
    }
    encrypted_text[j] = '\0';
}

void decrypt(char* encrypted_text, char* key, char* decrypted_text) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(encrypted_text); i++) {
        char c = toupper(encrypted_text[i]);
        if (isalpha(c)) {
            k = c - 'A';
            if (k < 0) {
                k += 26;
            }
            decrypted_text[j++] = key[k];
        } else {
            decrypted_text[j++] = c;
        }
    }
    decrypted_text[j] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_ENCRYPTED_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    generate_key(key, rand() % MAX_KEY_LENGTH + 1);
    printf("Key: %s\n", key);

    printf("Enter text to encrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    encrypt(text, key, encrypted_text);
    printf("Encrypted text: %s\n", encrypted_text);

    decrypt(encrypted_text, key, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}