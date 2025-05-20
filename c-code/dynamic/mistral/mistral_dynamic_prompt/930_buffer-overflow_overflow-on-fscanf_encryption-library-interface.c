#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_KEY_LEN 128

void encrypt(char* plaintext, char* key) {
    char ciphertext[MAX_KEY_LEN];
    // Deliberate buffer overflow vulnerability on fscanf
    if (fscanf(stdin, "%s", ciphertext) > MAX_KEY_LEN) {
        printf("Error: Key too long.\n");
        return;
    }

    // Pseudo encryption logic
    strcat(ciphertext, plaintext);
    printf("Encrypted: %s\n", ciphertext);
}

int main() {
    char plaintext[128];
    char key[128];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key (max 128 characters): ");
    fgets(key, sizeof(key), stdin);

    encrypt(plaintext, key);

    return 0;
}
