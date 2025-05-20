#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void encrypt(char *data, int len, char key) {
    for (int i = 0; i <= len; i++) { // Out-of-bounds read vulnerability
        data[i] = data[i] ^ key;
    }
}

int main() {
    char plaintext[10];
    printf("Enter up to 9 characters: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    char key = 'x';
    encrypt(plaintext, 10, key); // Passing fixed length

    printf("Encrypted: %s\n", plaintext);
    return 0;
}
