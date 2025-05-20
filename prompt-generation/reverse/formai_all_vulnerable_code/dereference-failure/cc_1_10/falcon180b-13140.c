//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *binary;
    char *decimal;
} conversion_t;

void convert_binary_to_decimal(conversion_t *conversion) {
    uint32_t decimal = 0;
    int i = strlen(conversion->binary) - 1;

    while (i >= 0) {
        if (conversion->binary[i] == '1') {
            decimal += pow(2, strlen(conversion->binary) - i - 1);
        }
        i--;
    }

    sprintf(conversion->decimal, "%d", decimal);
}

void convert_decimal_to_binary(conversion_t *conversion) {
    char *binary = malloc(33 * sizeof(char)); // Maximum 32-bit binary number is 32 1's + 1 null terminator

    int i = 0;
    while (conversion->decimal[i]!= '\0') {
        binary[i] = conversion->decimal[i] % 2 == 0? '0' : '1';
        i++;
    }

    binary[i] = '\0';
    strcpy(conversion->binary, binary);

    free(binary);
}

int main() {
    conversion_t conversion;

    printf("Enter a binary number:\n");
    scanf("%s", conversion.binary);

    printf("Enter a decimal number:\n");
    scanf("%s", conversion.decimal);

    if (strcmp(conversion.binary, "")!= 0) {
        convert_binary_to_decimal(&conversion);
        printf("Decimal equivalent: %s\n", conversion.decimal);
    }

    if (strcmp(conversion.decimal, "")!= 0) {
        convert_decimal_to_binary(&conversion);
        printf("Binary equivalent: %s\n", conversion.binary);
    }

    return 0;
}