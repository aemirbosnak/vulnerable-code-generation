//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>

int main() {
    char input[100];
    int hex_value = 0;
    int i, j;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Convert hexadecimal to decimal
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            hex_value += input[i] - '0';
        }
        else if (input[i] >= 'a' && input[i] <= 'f') {
            hex_value += input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F') {
            hex_value += input[i] - 'A' + 10;
        }
    }

    // Convert decimal to binary
    for (j = 31; j >= 0; j--) {
        if (hex_value & (1 << j)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }

    // Print the binary number
    printf("\nBinary: ");
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            printf("%c", input[i]);
        }
        else if (input[i] >= 'a' && input[i] <= 'f') {
            printf("%c", input[i]);
        }
        else if (input[i] >= 'A' && input[i] <= 'F') {
            printf("%c", input[i]);
        }
    }

    // Print the decimal number
    printf("\nDecimal: %d\n", hex_value);

    return 0;
}