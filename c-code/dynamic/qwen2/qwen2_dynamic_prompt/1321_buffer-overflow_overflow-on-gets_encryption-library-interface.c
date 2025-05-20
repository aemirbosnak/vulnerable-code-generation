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
    char buffer[16];
    printf("Enter your secret message: ");
    gets(buffer); // Vulnerable to buffer overflow

    int key;
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(buffer, key);
    printf("Encrypted message: %s\n", buffer);

    return 0;
}
