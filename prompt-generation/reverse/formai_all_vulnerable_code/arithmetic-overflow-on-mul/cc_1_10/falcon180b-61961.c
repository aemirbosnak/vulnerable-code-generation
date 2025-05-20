//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX 1000

int main() {
    char hex[MAX_HEX];
    char bin[MAX_HEX];
    int i, j, k;
    int len;
    int decimal = 0;
    int binary = 0;
    int temp = 0;
    int valid = 1;

    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX, stdin);

    // Remove newline character from input
    hex[strcspn(hex, "\n")] = '\0';

    len = strlen(hex);

    // Check for invalid characters
    for (i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            printf("Error: Invalid hexadecimal number\n");
            valid = 0;
            break;
        }
    }

    // Convert hexadecimal to decimal
    if (valid) {
        for (i = 0, j = strlen(hex) - 1; i < j; i++, j--) {
            if (isdigit(hex[i])) {
                decimal += (hex[i] - '0');
            } else {
                temp = 0;
                if (hex[i] >= 'A') {
                    temp += 10;
                }
                temp += hex[i] - '0';
                decimal += temp * 16;
            }
        }
    }

    // Convert decimal to binary
    if (valid) {
        while (decimal > 0) {
            temp = decimal % 2;
            binary = binary * 10 + temp;
            decimal /= 2;
        }

        // Print binary in reverse order
        for (i = strlen(bin) - 1, j = 0; i >= j; i--, j++) {
            printf("%d", bin[i]);
        }
    }

    return 0;
}