#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_PLAINTEXT_LENGTH 1000

char* read_key() {
    char *key = (char *) malloc(MAX_KEY_LENGTH * sizeof(char));
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    return key;
}

char* read_plaintext() {
    char *plaintext = (char *) malloc(MAX_PLAINTEXT_LENGTH * sizeof(char));
    printf("Enter the plaintext to encrypt: ");
    fgets(plaintext, MAX_PLAINTEXT_LENGTH, stdin);
    return plaintext;
}

void encrypt(char *key, char *plaintext) {
    // Pseudo-encryption algorithm (do not use this in real applications)
    for (int i = 0; plaintext[i]; i++) {
        plaintext[i] = plaintext[i] + key[i % strlen(key)];
    }
}

void print_result(char *result) {
    printf("Encrypted Text: %s\n", result);
}

int main() {
    char *key = read_key();
    char *plaintext = read_plaintext();
    char *result = malloc(MAX_PLAINTEXT_LENGTH * sizeof(char));

    encrypt(key, plaintext);
    strcpy(result, plaintext); // Overwrites memory for key variable

    print_result(result);

    free(key); // Forgot to free the memory allocated for the key
    free(plaintext);
    free(result);

    return 0;
}
