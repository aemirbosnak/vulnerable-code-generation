//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char hex[MAX_LENGTH] = {0};
    int i, j, len, decimal = 0;
    char *endptr;

    if (argc!= 2) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);
    len = strlen(hex);

    // Check if input is a valid hexadecimal number
    for (i = 0; i < len; i++) {
        if ((hex[i] < '0' || hex[i] > '9') && (hex[i] < 'A' || hex[i] > 'F')) {
            printf("Error: Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    for (i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert decimal to binary
    char binary[MAX_LENGTH] = {0};
    i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[i] = '\0';

    // Reverse binary string
    for (i = 0, j = strlen(binary) - 1; i < j; i++, j--) {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }

    // Print results
    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %d\n", decimal);
    printf("Binary: %s\n", binary);

    return 0;
}