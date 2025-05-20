#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *data) {
    char key[] = "secret";
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        data[i] ^= key[i % strlen(key)];
    }
}

int main() {
    char input[10];
    printf("Enter your secret message: ");
    gets(input); // Vulnerable to buffer overflow
    encrypt(input);
    printf("Encrypted message: %s\n", input);
    return 0;
}
