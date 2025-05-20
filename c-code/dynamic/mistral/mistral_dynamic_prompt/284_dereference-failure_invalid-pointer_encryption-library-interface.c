#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY_SIZE 256

void encrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] = toupper(plaintext[i]) - key[i % KEY_SIZE];
        if (plaintext[i] < 'A')
            plaintext[i] += 26;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./encrypt <key> <plaintext>\n");
        return 1;
    }

    char *key = argv[1];
    char *plaintext = argv[2];

    // Vulnerability: key and plaintext are the same memory location
    char *encrypted = (char *)malloc((strlen(plaintext) + 1) * sizeof(char));

    encrypt(key, key);
    strcpy(encrypted, key);

    printf("Encrypted text: %s\n", encrypted);

    free(encrypted);
    return 0;
}
