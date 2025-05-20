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

int main() {
    char buffer[10];
    strcpy(buffer, "Hello, World!");
    printf("Original: %s\n", buffer);

    // Out-of-bounds write example
    encrypt(buffer + 20, 3); // This will overwrite memory outside the buffer

    printf("Encrypted: %s\n", buffer);
    return 0;
}
