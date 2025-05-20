//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_TEXT_LENGTH 1024

void generate_key(char *key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}[]\\|:;<>,.?/";
    int charset_length = strlen(charset);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % charset_length];
    }
}

void encrypt(char *text, char *key, char *ciphertext) {
    int text_length = strlen(text);
    int key_length = strlen(key);

    int j = 0;

    for (int i = 0; i < text_length; i++) {
        char ch = toupper(text[i]);
        if (isalpha(ch)) {
            ch = (ch + key[j % key_length] - 'A') % 26 + 'A';
        }

        ciphertext[i] = ch;
        j++;
    }
}

void decrypt(char *ciphertext, char *key, char *text) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);

    int j = 0;

    for (int i = 0; i < ciphertext_length; i++) {
        char ch = toupper(ciphertext[i]);
        if (isalpha(ch)) {
            ch = (ch - key[j % key_length] + 26) % 26 + 'A';
        }

        text[i] = ch;
        j++;
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char ciphertext[MAX_TEXT_LENGTH];

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt(text, key, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, text);

    printf("Decrypted text: %s\n", text);

    return 0;
}