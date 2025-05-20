//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 32

void hex_string_to_decimal(const char *hex_str, int *decimal) {
    int base = 0;
    int len = strlen(hex_str);
    int i;

    for (i = len - 1; i >= 0; i--) {
        int power = i % 4;
        int digit = tolower(hex_str[i]) - '0';

        if (power == 0) {
            *decimal = *decimal << 4;
            *decimal |= digit;
        } else {
            int value = (digit * 16) << (12 - power);
            *decimal += value;
        }
    }
}

int main() {
    char hex_string[MAX_LENGTH];
    int decimal;

    printf("Enter a hexadecimal number: ");
    fgets(hex_string, sizeof(hex_string), stdin);

    // Remove newline character from the input
    hex_string[strcspn(hex_string, "\n")] = '\0';

    if (strlen(hex_string) > MAX_LENGTH) {
        printf("Error: Hexadecimal number too long.\n");
        return 1;
    }

    if (strlen(hex_string) % 2 == 1) {
        printf("Error: Hexadecimal number must have an even number of digits.\n");
        return 1;
    }

    hex_string_to_decimal(hex_string, &decimal);

    printf("The decimal equivalent of the hexadecimal number %s is: %#x\n", hex_string, decimal);

    return 0;
}