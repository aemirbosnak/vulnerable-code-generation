//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 64

int main(int argc, char *argv[]) {
    char input[MAX_HEX_LENGTH];
    char output[MAX_HEX_LENGTH * 2 + 1];
    int i, j, k;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_HEX_LENGTH, stdin);

    // Remove newline character from input
    j = strlen(input) - 1;
    if (input[j] == '\n') {
        input[j] = '\0';
    }

    // Check if input is a valid hexadecimal number
    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to ASCII
    for (i = 0, j = 0; i < strlen(input); i += 2, j++) {
        k = 0;
        if (isdigit(input[i])) {
            k = input[i] - '0';
        } else {
            k = toupper(input[i]) - 'A' + 10;
        }
        output[j] = k << 4;

        if (i + 1 < strlen(input)) {
            if (isdigit(input[i + 1])) {
                k = input[i + 1] - '0';
            } else {
                k = toupper(input[i + 1]) - 'A' + 10;
            }
            output[j] |= k;
        } else {
            output[j] |= '0';
        }
    }

    // Print ASCII representation of input
    printf("ASCII representation: %s\n", output);

    return 0;
}