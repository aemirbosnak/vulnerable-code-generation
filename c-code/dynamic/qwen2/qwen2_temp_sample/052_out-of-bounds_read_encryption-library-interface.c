#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

void decrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] -= key;
    }
}

int main() {
    char buffer[10];
    int key = 3;

    printf("Enter a message to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    encrypt(buffer, key);
    printf("Encrypted message: %s\n", buffer);

    decrypt(buffer, key);
    printf("Decrypted message: %s\n", buffer);

    return 0;
}
