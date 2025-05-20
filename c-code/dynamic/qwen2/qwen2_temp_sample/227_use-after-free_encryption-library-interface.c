#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char *plain_text = (char *)malloc(100 * sizeof(char));
    if (plain_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(plain_text, "This is a secret message");

    int key = 3;
    encrypt(plain_text, key);

    printf("Encrypted: %s\n", plain_text);
    free(plain_text); // Freeing the allocated memory

    // Use-after-free vulnerability
    printf("Decrypted: %s\n", plain_text); // Using freed memory

    return 0;
}
