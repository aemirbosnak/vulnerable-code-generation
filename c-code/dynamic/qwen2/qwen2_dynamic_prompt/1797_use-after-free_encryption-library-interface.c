#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += 3;
    }
}

void decrypt(char *data) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] -= 3;
    }
}

int main() {
    char *secret = (char *)malloc(20);
    if (secret == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(secret, "This is a secret message");

    printf("Original: %s\n", secret);

    encrypt(secret);
    printf("Encrypted: %s\n", secret);

    free(secret);

    // Use-after-free vulnerability
    printf("Decrypted: %s\n", secret); // This line will access freed memory

    return 0;
}
