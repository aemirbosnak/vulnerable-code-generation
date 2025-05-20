//Falcon-180B DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char* key, char* text, char* encrypted_text) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    int i, j;

    for (i = 0, j = 0; i < text_length; i++) {
        char c = tolower(text[i]);
        if (isalpha(c)) {
            int shift = (int)key[j % key_length] - 97; // assuming key contains only lowercase letters
            c += shift;
            if (c > 122) {
                c -= 26;
            } else if (c < 97) {
                c += 26;
            }
            encrypted_text[i] = c;
        } else {
            encrypted_text[i] = text[i];
        }
        j++;
    }
    encrypted_text[text_length] = '\0';
}

void decrypt(char* key, char* encrypted_text, char* decrypted_text) {
    int key_length = strlen(key);
    int encrypted_text_length = strlen(encrypted_text);
    int i, j;

    for (i = 0, j = 0; i < encrypted_text_length; i++) {
        char c = encrypted_text[i];
        if (isalpha(c)) {
            int shift = (int)key[j % key_length] - 97; // assuming key contains only lowercase letters
            c -= shift;
            if (c < 97) {
                c += 26;
            } else if (c > 122) {
                c -= 26;
            }
            decrypted_text[i] = c;
        } else {
            decrypted_text[i] = c;
        }
        j++;
    }
    decrypted_text[encrypted_text_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    encrypt(key, text, encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    printf("Enter the encrypted text to decrypt: ");
    scanf("%s", encrypted_text);

    decrypt(key, encrypted_text, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}