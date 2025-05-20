//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>

// Function to convert hex code to integer
int hexToDecimal(char hex[]) {
    int decimal = 0;
    int i = 0;

    while (hex[i] != '\0') {
        // returns digit value in integer form
        int digitValue = hex[i];

        if (digitValue >= '0' && digitValue <= '9') {
            digitValue = digitValue - '0';
        } else if (digitValue >= 'a' && digitValue <= 'f') {
            digitValue = digitValue - 'a' + 10;
        } else if (digitValue >= 'A' && digitValue <= 'F') {
            digitValue = digitValue - 'A' + 10;
        } else {
            printf("Invalid hex code!");
            return 0;
        }

        decimal = decimal * 16 + digitValue;
        i++;
    }

    return decimal;
}

// Function to convert decimal to RGB value
void decimalToRgb(int decimal, int *r, int *g, int *b) {
    *b = decimal & 0xff;
    decimal >>= 8;
    *g = decimal & 0xff;
    decimal >>= 8;
    *r = decimal & 0xff;
}

// Main function
int main() {
    char hex[7];

    // Get input hex code from user
    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%s", hex);

    // Convert hex code to decimal
    int decimal = hexToDecimal(hex);

    // Convert decimal to RGB value
    int r, g, b;
    decimalToRgb(decimal, &r, &g, &b);

    // Output RGB value
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);

    return 0;
}