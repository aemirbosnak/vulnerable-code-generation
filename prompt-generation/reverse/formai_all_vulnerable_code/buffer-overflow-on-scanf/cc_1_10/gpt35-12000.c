//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
char* encrypt(char* plain_text, int key) {
    int len = strlen(plain_text);
    char* cipher_text = (char*)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        // Shift the character by the key
        cipher_text[i] = (plain_text[i] + key) % 128;
    }

    return cipher_text;
}

// Function to perform decryption
char* decrypt(char* cipher_text, int key) {
    int len = strlen(cipher_text);
    char* plain_text = (char*)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        // Shift the character back by the key
        plain_text[i] = (cipher_text[i] - key) % 128;
    }

    return plain_text;
}

int main() {
    char plain_text[100];
    int key;
    printf("Enter the plain text: ");
    scanf("%[^\n]%*c", plain_text);
    printf("Enter the key: ");
    scanf("%d", &key);

    char* cipher_text = encrypt(plain_text, key);
    char* decrypted_text = decrypt(cipher_text, key);

    printf("Plain text: %s\n", plain_text);
    printf("Encrypted text: %s\n", cipher_text);
    printf("Decrypted text: %s\n", decrypted_text);

    free(cipher_text);
    free(decrypted_text);

    return 0;
}