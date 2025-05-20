//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

void hex_to_decimal(char* hex, int* decimal);
void decimal_to_hex(int decimal, char* hex);
void convert(char* input, char* output);

int main() {
    char input[MAX_HEX_LENGTH];
    char output[MAX_HEX_LENGTH];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    convert(input, output);

    printf("Decimal equivalent: %s\n", output);

    return 0;
}

void hex_to_decimal(char* hex, int* decimal) {
    int i = 0;
    int j = 0;
    int base = 1;

    *decimal = 0;

    while (hex[i]!= '\0') {
        if (isdigit(hex[i])) {
            *decimal += (hex[i] - '0') * base;
        } else if (isupper(hex[i])) {
            *decimal += (hex[i] - 'A' + 10) * base;
        } else if (islower(hex[i])) {
            *decimal += (hex[i] - 'a' + 10) * base;
        } else {
            *decimal = -1;
            break;
        }

        i++;
        base *= 16;
    }
}

void decimal_to_hex(int decimal, char* hex) {
    char temp[MAX_HEX_LENGTH];
    int i = 0;
    int j = 0;

    sprintf(temp, "%d", decimal);

    while (temp[i]!= '\0') {
        if (isdigit(temp[i])) {
            hex[j] = temp[i];
        } else {
            hex[j] = 'A' + (temp[i] - 10);
        }

        i++;
        j++;
    }

    hex[j] = '\0';
}

void convert(char* input, char* output) {
    int decimal = 0;
    int i = 0;
    int j = 0;

    hex_to_decimal(input, &decimal);

    if (decimal == -1) {
        strcpy(output, "Invalid hexadecimal number");
    } else {
        decimal_to_hex(decimal, output);
    }
}