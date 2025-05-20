//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_TEXT_SIZE 1000

void encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);

    if (text_len == 0 || key_len == 0) {
        return;
    }

    char *encrypted_text = (char *)malloc(text_len + 1);
    encrypted_text[text_len] = '\0';

    for (int i = 0; i < text_len; i++) {
        encrypted_text[i] = text[i] + key[i % key_len];
    }

    printf("Encrypted text: %s\n", encrypted_text);

    free(encrypted_text);
}

void decrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);

    if (text_len == 0 || key_len == 0) {
        return;
    }

    char *decrypted_text = (char *)malloc(text_len + 1);
    decrypted_text[text_len] = '\0';

    for (int i = 0; i < text_len; i++) {
        decrypted_text[i] = text[i] - key[i % key_len];
    }

    printf("Decrypted text: %s\n", decrypted_text);

    free(decrypted_text);
}

int main() {
    char text[] = "Hello, World!";
    char key[] = "secret";

    encrypt(text, key);
    decrypt(text, key);

    return 0;
}