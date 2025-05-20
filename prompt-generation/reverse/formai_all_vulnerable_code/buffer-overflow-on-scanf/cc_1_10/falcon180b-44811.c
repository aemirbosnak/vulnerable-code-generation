//Falcon-180B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_PLAINTEXT_LENGTH 1024
#define MAX_CIPHERTEXT_LENGTH (MAX_PLAINTEXT_LENGTH + 1)

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j, k;
    int length = strlen(plaintext);
    int key_length = strlen(key);

    for (i = 0, j = 0; i < length; i++) {
        char c = tolower(plaintext[i]);
        if (isalpha(c)) {
            c = (c - 'a' + key_length) % 26 + 'a';
            ciphertext[j++] = c;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j, k;
    int length = strlen(ciphertext);
    int key_length = strlen(key);

    for (i = 0, j = 0; i < length; i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            c = (c - 'a' - key_length + 26) % 26 + 'a';
            plaintext[j++] = c;
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char ciphertext[MAX_CIPHERTEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}