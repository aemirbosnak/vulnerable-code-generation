#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *input) {
    char encrypted[10];
    strcpy(encrypted, input);
    printf("Encrypted: %s\n", encrypted);
}

int main() {
    char input[10];
    printf("Enter message to encrypt (up to 9 characters):\n");
    scanf("%s", input);
    encrypt(input);
    return 0;
}
