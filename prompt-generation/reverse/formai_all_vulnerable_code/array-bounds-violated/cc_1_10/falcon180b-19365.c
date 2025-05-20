//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main(int argc, char *argv[]) {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int i, j, len;

    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Remove newline character from input
    input[len - 1] = '\0';

    // Check if input is a valid hexadecimal number
    for (i = 0; i < len; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    for (i = 0, j = 0; i < len; i++) {
        if (isdigit(input[i])) {
            output[j++] = input[i];
        } else {
            if (input[i] >= 'A' && input[i] <= 'F') {
                output[j++] = input[i] - 'A' + 10;
            } else if (input[i] >= 'a' && input[i] <= 'f') {
                output[j++] = input[i] - 'a' + 10;
            } else {
                printf("Error: Invalid hexadecimal number.\n");
                return 1;
            }
        }
    }
    output[j] = '\0';

    // Convert decimal to binary
    char binary[MAX_LEN];
    int k = 0;
    for (i = strlen(output) - 1; i >= 0; i--) {
        int rem = output[i] % 2;
        binary[k++] = rem + '0';
        output[i] /= 2;
    }
    binary[k] = '\0';

    // Output results
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %s\n", output);
    printf("Binary: %s\n", binary);

    return 0;
}