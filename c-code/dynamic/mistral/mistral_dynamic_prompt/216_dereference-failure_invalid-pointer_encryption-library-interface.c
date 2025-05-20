#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Pseudo Encryption Library
void encrypt(char* input, char* output) {
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        output[i] = toupper(input[i]) + 2;
    }
    output[i] = '\0';
}

int main() {
    char userInput[100];
    char encrypted[100];

    printf("Enter a string to encrypt:\n");
    scanf("%s", userInput);

    // Allocate memory for the encrypted string, forgetting to consider the null character
    encrypt(userInput, encrypted);

    printf("Encrypted string: %s\n", encrypted);

    return 0;
}
