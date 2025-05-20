//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* encrypted_text) {
    int key_length = strlen(key);
    int text_length = strlen(text);

    if (key_length < 1 || text_length < 1) {
        printf("Error: Invalid key or text length.\n");
        return;
    }

    for (int i = 0; i < text_length; i++) {
        encrypted_text[i] = text[i] ^ key[i % key_length];
    }

    encrypted_text[text_length] = '\0';
    printf("Encrypted text: %s\n", encrypted_text);
}

void decrypt(char* key, char* encrypted_text, char* decrypted_text) {
    int key_length = strlen(key);
    int encrypted_text_length = strlen(encrypted_text);

    if (key_length < 1 || encrypted_text_length < 1) {
        printf("Error: Invalid key or encrypted text length.\n");
        return;
    }

    for (int i = 0; i < encrypted_text_length; i++) {
        decrypted_text[i] = encrypted_text[i] ^ key[i % key_length];
    }

    decrypted_text[encrypted_text_length] = '\0';
    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    printf("Enter text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Encrypt or decrypt? (e/d): ");
    char option;
    scanf(" %c", &option);

    if (option == 'e') {
        encrypt(key, text, encrypted_text);
    } else if (option == 'd') {
        decrypt(key, encrypted_text, decrypted_text);
    } else {
        printf("Invalid option.\n");
        return 1;
    }

    return 0;
}