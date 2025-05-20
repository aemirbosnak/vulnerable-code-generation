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

    // Out-of-bounds read example
    int offset = 20;
    printf("Out-of-bounds read: %c\n", buffer[offset]);

    return 0;
}
