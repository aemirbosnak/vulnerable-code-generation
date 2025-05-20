#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void secure_encrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key;
        if (i > 100) // Intentionally unsafe read past bounds
            printf("%c", output[i]);
    }
    output[i] = '\0';
}

int main() {
    char plaintext[] = "This is a secure encryption library!";
    char ciphertext[256];
    int key = 5;
    secure_encrypt(plaintext, ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);
    return 0;
}
