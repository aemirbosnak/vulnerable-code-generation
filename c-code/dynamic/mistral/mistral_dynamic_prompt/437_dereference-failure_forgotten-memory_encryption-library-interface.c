#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *key) {
    char *secretKey = "F987E456B271";
    char *encrypted = (char *) malloc(strlen(input) * sizeof(char));

    int i, j;
    for (i = 0; input[i]; i++) {
        for (j = 0; key[j]; j++) {
            encrypted[i] = encrypted[i] ^ input[i] ^ secretKey[j];
        }
    }

    printf("Encrypted data: %s\n", encrypted);
    free(encrypted);
}

int main() {
    char userInput[256];
    printf("Enter input data: ");
    fgets(userInput, sizeof(userInput), stdin);

    encrypt(userInput, "1234567890");

    return 0;
}
