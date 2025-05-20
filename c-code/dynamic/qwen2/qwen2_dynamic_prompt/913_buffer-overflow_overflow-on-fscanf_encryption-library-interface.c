#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    while (*data) {
        *data = *data + key;
        data++;
    }
}

int main() {
    char input[10];
    int key;

    printf("Enter data to encrypt: ");
    fscanf(stdin, "%s", input); // Vulnerable to buffer overflow

    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(input, key);

    printf("Encrypted data: %s\n", input);

    return 0;
}
