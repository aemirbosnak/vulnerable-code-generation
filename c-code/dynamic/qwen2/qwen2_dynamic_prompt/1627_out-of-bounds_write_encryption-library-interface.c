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
    strcpy(buffer, "Hello");
    printf("Original: %s\n", buffer);

    // Out-of-bounds write
    encrypt(buffer + 6, 3); // This will overwrite memory outside the buffer

    printf("Encrypted: %s\n", buffer);
    return 0;
}
