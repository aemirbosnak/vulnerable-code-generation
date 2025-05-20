#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] + key;
    }
    output[len] = '\0'; // Out of bounds write vulnerability
}

void decrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] - key;
    }
    output[len] = '\0'; // Out of bounds write vulnerability
}

int main() {
    char input[100];
    char encrypted[100];
    char decrypted[100];
    int key = 3;

    printf("Enter a string to encrypt:\n");
    fgets(input, 100, stdin);

    encrypt(input, encrypted, key);
    printf("Encrypted:\n%s\n", encrypted);

    decrypt(encrypted, decrypted, key);
    printf("Decrypted:\n%s\n", decrypted);

    return 0;
}
