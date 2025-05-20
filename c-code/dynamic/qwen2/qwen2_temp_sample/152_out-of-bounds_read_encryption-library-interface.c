#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key) {
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char buffer[10];
    printf("Enter a string to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);
    int key = 3;

    // Out-of-bounds read vulnerability
    printf("Encrypted string: %s\n", buffer + 20);

    return 0;
}
