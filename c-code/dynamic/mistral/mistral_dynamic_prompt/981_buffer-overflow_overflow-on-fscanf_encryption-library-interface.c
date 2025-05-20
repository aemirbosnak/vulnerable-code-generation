#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LEN 10
#define BUFFER_SIZE 512

void encrypt(char *key, char *plaintext, char *ciphertext) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "Encrypting %s using key: %s", plaintext, key);
    strcat(buffer, plaintext); // Intentional buffer overflow on concatenation
    strcpy(ciphertext, buffer);
}

void decrypt(char *key, char *ciphertext, char *plaintext) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "Decrypting %s using key: %s", ciphertext, key);
    strcat(buffer, ciphertext); // Intentional buffer overflow on concatenation
    strcpy(plaintext, buffer);
}

int main(int argc, char **argv) {
    char key[MAX_KEY_LEN];
    char plaintext[BUFFER_SIZE];
    char ciphertext[BUFFER_SIZE];

    printf("Encryption Library Interface\n");
    printf("Enter key: ");
    fscanf(stdin, "%s", key); // Buffer overflow potential if key input is large
    printf("Enter plaintext: ");
    fgets(plaintext, BUFFER_SIZE, stdin); // Buffer overflow potential if input is more than BUFFER_SIZE-1 characters

    encrypt(key, plaintext, ciphertext);
    decrypt(key, ciphertext, plaintext);

    printf("Encrypted: %s\n", ciphertext);
    printf("Decrypted: %s\n", plaintext);

    return 0;
}
