//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int decimal;
    int binary[32];
    bool error = false;

    // Ask user for conversion type
    printf("Enter conversion type (d for decimal to binary, b for binary to decimal): ");
    char conversionType;
    scanf(" %c", &conversionType);

    // Convert binary to decimal
    if (conversionType == 'd') {
        // Ask user for binary value
        printf("Enter binary value: ");
        scanf("%d", &decimal);

        // Convert binary to decimal
        for (int i = 0; i < 32; i++) {
            binary[i] = 0;
        }

        while (decimal > 0) {
            int remainder = decimal % 2;
            binary[31] = remainder;
            decimal = decimal / 2;
        }

        // Print decimal value
        printf("Binary value %d is %d in decimal.\n", decimal, binary[0]);
    }

    // Convert decimal to binary
    else if (conversionType == 'b') {
        // Ask user for decimal value
        printf("Enter decimal value: ");
        scanf("%d", &decimal);

        // Convert decimal to binary
        for (int i = 0; i < 32; i++) {
            binary[i] = 0;
        }

        while (decimal > 0) {
            int remainder = decimal % 2;
            binary[31] = remainder;
            decimal = decimal / 2;
        }

        // Print binary value
        printf("Decimal value %d is %d in binary.\n", decimal, binary[0]);
    }

    // Handle invalid conversion type
    else {
        printf("Invalid conversion type.\n");
        error = true;
    }

    // Handle invalid input
    if (error) {
        printf("Invalid input.\n");
        exit(1);
    }

    return 0;
}