//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000

int main() {
    char hex[MAX_HEX_LENGTH];
    char *decimal;
    int hexLength, decimalLength, i, j, value;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hexLength = strlen(hex);

    if (hexLength == 0) {
        printf("Invalid input!\n");
        return 1;
    }

    if (hexLength % 2!= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    decimal = (char *)malloc(MAX_HEX_LENGTH * sizeof(char));
    decimalLength = 0;

    for (i = hexLength - 1, j = 0; i >= 0; i--, j++) {
        if (isdigit(hex[i])) {
            value = hex[i] - '0';
        } else if (tolower(hex[i]) >= 'a' && tolower(hex[i]) <= 'f') {
            value = tolower(hex[i]) - 'a' + 10;
        } else {
            printf("Invalid input!\n");
            free(decimal);
            return 1;
        }

        if (value > 15) {
            printf("Invalid input!\n");
            free(decimal);
            return 1;
        }

        decimal[decimalLength++] = value + '0';
    }

    printf("Decimal equivalent: %s\n", decimal);
    free(decimal);

    return 0;
}