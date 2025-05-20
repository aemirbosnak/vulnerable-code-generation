#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption library interface
void encrypt(char* plaintext, char* ciphertext, int size) {
    for (int i = 0; i < size; i++) {
        ciphertext[i] = plaintext[i] + 3; // Simple XOR encryption for simplicity
    }
}

int main() {
    char input[10]; // Small buffer for user input
    char key[20]; // Key for encryption
    printf("Enter plaintext:\n");
    scanf("%s", input); // Buffer overflow vulnerability

    printf("Enter encryption key (20 characters):\n");
    scanf("%s", key);

    int plaintext_len = strlen(input);
    char ciphertext[plaintext_len];
    encrypt(input, ciphertext, plaintext_len);

    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
