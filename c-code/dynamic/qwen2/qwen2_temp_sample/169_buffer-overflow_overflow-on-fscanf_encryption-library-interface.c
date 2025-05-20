#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char input[20];
    int key;

    printf("Enter data to encrypt: ");
    if (fscanf(stdin, "%19s", input) == EOF) {
        perror("Error reading input");
        return EXIT_FAILURE;
    }

    printf("Enter encryption key: ");
    if (fscanf(stdin, "%d", &key) == EOF) {
        perror("Error reading key");
        return EXIT_FAILURE;
    }

    encrypt(input, key);
    printf("Encrypted data: %s\n", input);

    return EXIT_SUCCESS;
}
