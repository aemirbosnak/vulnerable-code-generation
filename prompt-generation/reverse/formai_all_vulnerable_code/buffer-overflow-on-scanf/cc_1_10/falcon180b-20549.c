//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_TEXT_LENGTH 1000

char key[MAX_KEY_LENGTH];
char text[MAX_TEXT_LENGTH];
char encrypted_text[MAX_TEXT_LENGTH];

void generate_key() {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt() {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            encrypted_text[i] = text[i] + key[i % MAX_KEY_LENGTH];
        } else {
            encrypted_text[i] = text[i];
        }
    }
    encrypted_text[strlen(text)] = '\0';
}

void decrypt() {
    for (int i = 0; i < strlen(encrypted_text); i++) {
        if (isalpha(encrypted_text[i])) {
            text[i] = encrypted_text[i] - key[i % MAX_KEY_LENGTH];
        } else {
            text[i] = encrypted_text[i];
        }
    }
    text[strlen(encrypted_text)] = '\0';
}

int main() {
    printf("Enter the encryption key (max %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    printf("Enter the text to encrypt/decrypt (max %d characters): ", MAX_TEXT_LENGTH);
    scanf("%s", text);

    generate_key();
    encrypt();
    printf("Encrypted text: %s\n", encrypted_text);

    decrypt();
    printf("Decrypted text: %s\n", text);

    return 0;
}