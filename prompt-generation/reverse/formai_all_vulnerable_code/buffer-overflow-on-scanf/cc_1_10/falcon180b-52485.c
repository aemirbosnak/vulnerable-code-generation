//Falcon-180B DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_PLAIN_TEXT_LEN 1000

char key[MAX_KEY_LEN];
char plain_text[MAX_PLAIN_TEXT_LEN];
char cipher_text[MAX_PLAIN_TEXT_LEN];

void generate_key() {
    printf("Enter encryption key (max %d characters): ", MAX_KEY_LEN - 1);
    scanf("%s", key);
}

void get_plain_text() {
    printf("Enter plain text to encrypt: ");
    fgets(plain_text, MAX_PLAIN_TEXT_LEN, stdin);
    plain_text[strcspn(plain_text, "\n")] = '\0';
}

void encrypt() {
    int i, j;
    for (i = 0, j = 0; i < strlen(plain_text); i++) {
        if (isalpha(plain_text[i])) {
            plain_text[i] = toupper(plain_text[i]);
            cipher_text[j++] = plain_text[i] ^ key[i % strlen(key)];
        } else {
            cipher_text[j++] = plain_text[i];
        }
    }
    cipher_text[j] = '\0';
}

void decrypt() {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++) {
        if (isalpha(cipher_text[i])) {
            cipher_text[i] = toupper(cipher_text[i]);
            plain_text[j++] = cipher_text[i] ^ key[i % strlen(key)];
        } else {
            plain_text[j++] = cipher_text[i];
        }
    }
    plain_text[j] = '\0';
}

int main() {
    generate_key();
    get_plain_text();
    encrypt();
    printf("Cipher text: %s\n", cipher_text);
    decrypt();
    printf("Plain text: %s\n", plain_text);
    return 0;
}