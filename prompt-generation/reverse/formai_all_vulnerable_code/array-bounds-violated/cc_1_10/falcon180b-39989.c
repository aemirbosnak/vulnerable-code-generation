//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 1000

int main() {
    char input[MAX_CHARS];
    char binary[MAX_CHARS];
    int i, j;
    bool is_valid_input = true;

    printf("Enter a string to convert to binary: ");
    fgets(input, MAX_CHARS, stdin);

    // Check if input is valid
    for (i = 0; i < strlen(input); i++) {
        if (!isprint(input[i])) {
            is_valid_input = false;
            break;
        }
    }

    if (!is_valid_input) {
        printf("Invalid input. Please enter a string with only printable characters.\n");
        return 1;
    }

    // Convert string to binary
    for (i = 0; i < strlen(input); i++) {
        j = 0;
        while (true) {
            if (input[i] == '0') {
                binary[j] = '0000';
                j += 4;
                break;
            } else if (input[i] == '1') {
                binary[j] = '0001';
                j += 4;
                break;
            } else {
                if (j >= MAX_CHARS - 4) {
                    printf("Input is too long. Please enter a shorter string.\n");
                    return 1;
                }
                binary[j] = input[i];
                j++;
            }
        }
    }

    binary[j] = '\0';

    // Print binary string
    printf("Binary string: %s\n", binary);

    return 0;
}