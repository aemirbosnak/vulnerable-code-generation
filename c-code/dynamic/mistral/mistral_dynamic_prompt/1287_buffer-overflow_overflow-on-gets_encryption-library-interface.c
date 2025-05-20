#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i]; i++) {
        ciphertext[i] = plaintext[i] - 13;
        if (ciphertext[i] < 'A') ciphertext[i] += 26;
    }
    ciphertext[i] = '\0';
}

int main(int argc, char *argv[]) {
    char plaintext[BUFFER_SIZE];
    char ciphertext[BUFFER_SIZE];

    printf("Encryption Tool v1.0\n");
    printf("Enter plaintext: ");
    gets(plaintext);

    encrypt(plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
