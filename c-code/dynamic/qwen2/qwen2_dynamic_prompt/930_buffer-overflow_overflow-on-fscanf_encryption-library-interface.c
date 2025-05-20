#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data) {
    int key = 42;
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char input[10];
    printf("Enter your secret message: ");
    fscanf(stdin, "%s", input); // Vulnerable to buffer overflow

    encrypt(input);
    printf("Encrypted message: %s\n", input);

    return 0;
}
