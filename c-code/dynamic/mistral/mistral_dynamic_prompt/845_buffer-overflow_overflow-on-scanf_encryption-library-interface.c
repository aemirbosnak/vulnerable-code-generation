#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *input) {
    char secretKey[10] = "1234567890";
    char encrypted[100];

    int i, j;
    for (i = 0, j = 0; input[i]; i++) {
        encrypted[j++] = (input[i] + secretKey[i % 10]) % 256;
    }
    encrypted[j] = '\0';
}

int main() {
    char input[256];
    printf("Enter the message to encrypt (up to 255 characters):\n");
    scanf("%s", input);

    encrypt(input);
    printf("Encrypted message: %s\n", input);
    return 0;
}
