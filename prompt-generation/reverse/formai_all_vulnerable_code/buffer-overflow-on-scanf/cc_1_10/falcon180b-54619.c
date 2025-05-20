//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;
    int i;
    int j;
    int hex_value;
    int decimal_value;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);
    length = strlen(input);

    if (length > MAX_LENGTH) {
        printf("Error: Input is too long.\n");
        return 1;
    }

    for (i = 0; i < length; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Input is not a valid hexadecimal number.\n");
            return 1;
        }
    }

    for (i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        hex_value = toupper(input[i]) - '0';
        if (hex_value > 9) {
            hex_value -= 7;
        }
        decimal_value = hex_value * 16;
        decimal_value += toupper(input[j]) - '0';
        if (decimal_value > 9) {
            decimal_value += 6;
        }
        output[i + j / 2] = decimal_value + '0';
    }

    output[i + j / 2] = '\0';

    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %s\n", output);

    return 0;
}