//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

bool isValidHex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

int main() {
    char input[MAX_LENGTH];
    char* hexOutput;
    int decimalOutput;
    int length;
    int i;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    // Remove newline character
    input[length - 1] = '\0';

    // Check if input is valid hexadecimal
    for (i = 0; i < length; i++) {
        if (!isValidHex(input[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            exit(1);
        }
    }

    hexOutput = malloc(2 * length + 1);
    if (hexOutput == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    decimalOutput = 0;
    for (i = 0; i < length; i++) {
        if (isupper(input[i])) {
            hexOutput[i * 2] = input[i] - 'A' + 10;
        } else if (islower(input[i])) {
            hexOutput[i * 2] = input[i] - 'a' + 10;
        } else {
            hexOutput[i * 2] = input[i] - '0';
        }
        decimalOutput = (decimalOutput * 16) + (hexOutput[i * 2] - '0');
    }

    printf("Decimal output: %d\n", decimalOutput);
    printf("Hexadecimal output: %s\n", hexOutput);

    free(hexOutput);
    return 0;
}