//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_ALPHABET_SIZE 26

char alien_alphabet[ALIEN_ALPHABET_SIZE] = {'$', '%', '&', '*', '+', '!', '@', '#', '^', '(', ')', '_', '=', '|', '~', '-', '+', '[', ']', '{', '}', ';'};

void alienEncryption(char *input, char *output, int inputLen) {
    for (int i = 0; i < inputLen; i++) {
        for (int j = 0; j < ALIEN_ALPHABET_SIZE; j++) {
            if (input[i] == (char)(j + 'a')) {
                output[i] = alien_alphabet[j];
                break;
            }
        }
    }
}

void alienDecryption(char *input, char *output, int inputLen) {
    for (int i = 0; i < inputLen; i++) {
        for (int j = 0; j < ALIEN_ALPHABET_SIZE; j++) {
            if (input[i] == alien_alphabet[j]) {
                output[i] = (char)(j + 'a');
                break;
            }
        }
    }
}

int main() {
    char input[101];
    char output[101];

    printf("Enter English text: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character

    int inputLen = strlen(input);

    // Alien Encryption
    alienEncryption(input, output, inputLen);

    printf("\nEncrypted Alien text: ");
    for (int i = 0; i < inputLen; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    // Alien Decryption
    char decryptedInput[101];
    alienDecryption(output, decryptedInput, inputLen);

    printf("Decrypted English text: ");
    for (int i = 0; i < inputLen; i++) {
        printf("%c", decryptedInput[i]);
    }
    printf("\n");

    return 0;
}