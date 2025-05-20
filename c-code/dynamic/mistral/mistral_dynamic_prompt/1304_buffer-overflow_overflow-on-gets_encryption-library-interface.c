#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char* key, char* input, char* output) {
    strcpy(output, key);
    strcat(output, input);
    printf("Encrypted: %s\n", output);
}

int main() {
    char key[10];
    char input[100];
    char output[10];

    printf("Enter encryption key (up to 10 characters): ");
    gets(key);
    printf("Enter data to encrypt (up to 100 characters): ");
    gets(input);

    encrypt(key, input, output);
    return 0;
}
