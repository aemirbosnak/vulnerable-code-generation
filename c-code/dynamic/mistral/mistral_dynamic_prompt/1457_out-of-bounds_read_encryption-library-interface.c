#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10

void encrypt(char* input, char* output) {
    char key[] = "SuperSecretKey123";
    int i, j;

    for (i = 0; input[i]; i++) {
        j = (input[i] - key[i % strlen(key)]) % 256;
        output[i] = (char)j;
    }
    output[i] = '\0';
}

void decrypt(char* encrypted, char* plaintext) {
    char key[] = "SuperSecretKey123";
    int i, j;

    for (i = 0; encrypted[i]; i++) {
        j = (encrypted[i] + key[i % strlen(key)]) % 256;
        plaintext[i] = (char)j;
    }
    plaintext[i] = '\0';
}

int main() {
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    char encrypted[MAX_BUFFER_SIZE];
    char key[] = "SuperSecretKey123";

    printf("Enter plaintext: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    encrypt(input, output);
    printf("Encrypted text: %s\n", output);

    decrypt(encrypted, input);
    printf("Decrypted text: %s\n", input);

    printf("Enter a larger amount of encrypted text: ");
    fgets(encrypted, MAX_BUFFER_SIZE, stdin);
    decrypt(encrypted, input + strlen(input));

    return 0;
}
