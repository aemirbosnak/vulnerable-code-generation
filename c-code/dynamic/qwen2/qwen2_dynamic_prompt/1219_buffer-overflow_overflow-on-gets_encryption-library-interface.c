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
    char input[10];
    printf("Enter your message: ");
    gets(input); // Vulnerable to buffer overflow

    int key;
    printf("Enter encryption key: ");
    scanf("%d", &key);

    encrypt(input, key);
    printf("Encrypted message: %s\n", input);

    return 0;
}
