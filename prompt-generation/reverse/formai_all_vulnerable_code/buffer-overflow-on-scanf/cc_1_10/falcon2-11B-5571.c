//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16
#define ENCRYPT 0
#define DECRYPT 1

char* encrypt(char* plaintext, int mode) {
    char* ciphertext = (char*)malloc(strlen(plaintext) * sizeof(char));
    char* key = (char*)malloc(KEY_SIZE * sizeof(char));

    // Generate random key
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = 'A' + rand() % 26;
    }

    // Encrypt or decrypt plaintext based on mode
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }

    // Reverse ciphertext
    for (int i = 0; i < strlen(ciphertext) / 2; i++) {
        ciphertext[i] ^= ciphertext[strlen(ciphertext) - 1 - i];
    }

    free(key);
    return ciphertext;
}

int main() {
    char plaintext[100];
    char ciphertext[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character from input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Get mode from user input
    int mode;
    scanf("%d", &mode);

    char* ciphertext_ptr = NULL;
    if (mode == ENCRYPT) {
        ciphertext_ptr = encrypt(plaintext, ENCRYPT);
    } else if (mode == DECRYPT) {
        ciphertext_ptr = encrypt(plaintext, DECRYPT);
    } else {
        printf("Invalid mode\n");
        return 0;
    }

    printf("Ciphertext: %s\n", ciphertext_ptr);

    free(ciphertext_ptr);

    return 0;
}