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

    // Out-of-bounds read
    printf("%c\n", buffer[20]);

    return 0;
}
