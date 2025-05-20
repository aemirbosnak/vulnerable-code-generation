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
    printf("Enter a string to encrypt: ");
    scanf("%s", input);
    int key;
    printf("Enter an encryption key: ");
    scanf("%d", &key);
    encrypt(input, key);
    printf("Encrypted string: %s\n", input);
    return 0;
}
