//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH * 3];
    int i, j, len;
    int is_valid_hex = 1;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_LENGTH, stdin);
    len = strlen(input);

    // Remove trailing whitespace
    input[len - 1] = '\0';

    // Check if input is empty
    if (len == 0) {
        printf("Error: Input is empty.\n");
        return 1;
    }

    // Check if input is valid hexadecimal
    for (i = 0; i < len; i++) {
        if (!isxdigit(input[i])) {
            is_valid_hex = 0;
            break;
        }
    }

    if (!is_valid_hex) {
        printf("Error: Input is not a valid hexadecimal number.\n");
        return 1;
    }

    // Convert hexadecimal to ASCII
    for (i = 0, j = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            output[j++] = input[i];
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            output[j++] = input[i] - 'A' + 10;
        } else if (input[i] >= 'a' && input[i] <= 'f') {
            output[j++] = input[i] - 'a' + 10;
        }
    }

    output[j] = '\0';

    // Print the ASCII representation
    printf("The ASCII representation of %s is: %s\n", input, output);

    return 0;
}