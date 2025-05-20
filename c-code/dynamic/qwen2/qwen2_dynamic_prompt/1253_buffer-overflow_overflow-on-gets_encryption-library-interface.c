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
    printf("Enter a string to encrypt: ");
    gets(buffer); // Vulnerable to buffer overflow
    int key = 3;
    encrypt(buffer, key);
    printf("Encrypted string: %s\n", buffer);
    return 0;
}
