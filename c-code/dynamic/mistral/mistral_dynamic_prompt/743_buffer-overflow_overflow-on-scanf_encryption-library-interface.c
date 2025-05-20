#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = toupper(input[i]) + 3;
        if (i + 1 == strlen(input)) {
            output[++i] = '\0';
        }
    }
}

int main() {
    char input[10];
    char output[10];
    printf("Enter the text to encrypt (up to 10 characters): ");
    scanf("%s", input);
    encrypt(input, output);
    printf("Encrypted text: %s\n", output);
    return 0;
}
