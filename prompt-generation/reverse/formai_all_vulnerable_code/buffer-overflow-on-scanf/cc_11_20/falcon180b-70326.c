//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char hex[100];
    char dec[100];
    char bin[100];
    int i, j, len;

    printf("Enter the color code: ");
    scanf("%s", input);

    len = strlen(input);

    // Check for valid input
    if (len!= 6 && len!= 8) {
        printf("Invalid input. Please enter a valid color code.\n");
        return 0;
    }

    // Check for hex input
    if (len == 6) {
        for (i = 0; i < len; i++) {
            if (!isxdigit(input[i])) {
                printf("Invalid input. Please enter a valid hexadecimal color code.\n");
                return 0;
            }
        }

        strcpy(hex, input);
        strcat(hex, "#");

        // Convert hex to decimal
        for (i = 0, j = 0; i < 6; i += 2, j++) {
            sscanf(hex + i, "%2hhx", &dec[j]);
        }

        // Convert decimal to binary
        for (i = 0, j = 0; i < 3; i++) {
            sprintf(bin + j, "%08b", dec[i]);
            j += 8;
        }

        printf("Hex: %s\n", hex);
        printf("Decimal: %s\n", dec);
        printf("Binary: %s\n", bin);
    }
    // Check for rgb input
    else {
        for (i = 0; i < len; i++) {
            if (!isdigit(input[i])) {
                printf("Invalid input. Please enter a valid RGB color code.\n");
                return 0;
            }
        }

        strcpy(hex, input);
        strcat(hex, "#");

        // Convert rgb to hex
        for (i = 0, j = 0; i < 6; i += 2, j++) {
            sscanf(hex + i, "%2hhx", &dec[j]);
        }

        // Convert hex to binary
        for (i = 0, j = 0; i < 3; i++) {
            sprintf(bin + j, "%08b", dec[i]);
            j += 8;
        }

        printf("RGB: %s\n", hex);
        printf("Hex: %s\n", dec);
        printf("Binary: %s\n", bin);
    }

    return 0;
}