//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* This program implements a simple encryption algorithm using XOR and Caesar Cipher */

// Function to encrypt using XOR
void XORCipher(char *input, char *output, uint8_t key) {
    int i, len;
    len = strlen(input);
    for (i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }
    output[i] = '\0';
}

// Function to encrypt using Caesar Cipher
void caesarCipher(char *input, char *output, uint8_t key) {
    int i, len;
    len = strlen(input);
    for (i = 0; i < len; i++) {
        output[i] = ((input[i] + key) % 26) + 'A';
    }
    output[i] = '\0';
}

int main() {
    char text[100], encrypted[100], decrypted[100];
    int i, len, choice;
    uint8_t key;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // removing the newline character
    len = strlen(text);
    if (text[len-1] == '\n') {
        text[len-1] = '\0';
    }

    printf("Enter encryption key: ");
    scanf("%hhu", &key);

    printf("\nChoose type of encryption: \n");
    printf("1. XOR Cipher\n");
    printf("2. Caesar Cipher\n");
    printf("Choice (1/2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            XORCipher(text, encrypted, key);
            printf("\nEncrypted Text: %s\n", encrypted);
            XORCipher(encrypted, decrypted, key);
            printf("Decrypted Text: %s\n", decrypted);
            break;
        case 2:
            caesarCipher(text, encrypted, key);
            printf("\nEncrypted Text: %s\n", encrypted);
            break;
        default:
            printf("\nInvalid Choice!\n");
    }

    return 0;
}