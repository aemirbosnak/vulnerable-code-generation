//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1024

void encrypt(char *key, char *text) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    char encrypted_text[MAX_TEXT_LENGTH];
    int j = 0;

    for (int i = 0; i < text_length; i++) {
        char c = text[i];
        if (isalpha(c)) {
            c = (c + key[j % key_length] - 'a' + 26) % 26 + 'a';
            encrypted_text[i] = c;
        } else {
            encrypted_text[i] = c;
        }
        j++;
    }

    encrypted_text[text_length] = '\0';

    printf("Encrypted text: %s\n", encrypted_text);
}

void decrypt(char *key, char *text) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    char decrypted_text[MAX_TEXT_LENGTH];
    int j = 0;

    for (int i = 0; i < text_length; i++) {
        char c = text[i];
        if (isalpha(c)) {
            c = (c - key[j % key_length] + 26) % 26 + 'a';
            decrypted_text[i] = c;
        } else {
            decrypted_text[i] = c;
        }
        j++;
    }

    decrypted_text[text_length] = '\0';

    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Enter encryption key (up to %d characters): ", MAX_KEY_LENGTH - 1);
    scanf("%s", key);

    printf("Enter text to encrypt/decrypt: ");
    scanf("%s", text);

    encrypt(key, text);
    decrypt(key, text);

    return 0;
}