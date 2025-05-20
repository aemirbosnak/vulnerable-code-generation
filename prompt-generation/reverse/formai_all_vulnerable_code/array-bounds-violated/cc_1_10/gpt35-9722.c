//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hexArray[16] = {"0", "1", "2", "3", "4", "5", "6", "7",
                      "8", "9", "A", "B", "C", "D", "E", "F"};

void decimalToHexadecimal(int decimalValue) {
    int quotient = decimalValue / 16;
    int remainder = decimalValue % 16;
    if (quotient != 0) {
        decimalToHexadecimal(quotient);
    }
    printf("%s", hexArray[remainder]);
}

int hexadecimalToDecimal(char *hexValue) {
    int hexLength = strlen(hexValue);
    int decimalValue = 0;
    for (int i = 0; i < hexLength; i++) {
        char currentHex = toupper(hexValue[hexLength - i - 1]);
        int decimal = 0;
        if (currentHex >= '0' && currentHex <= '9') {
            decimal = currentHex - '0';
        } else if (currentHex >= 'A' && currentHex <= 'F') {
            decimal = currentHex - 'A' + 10;
        } else {
            printf("Invalid Hexadecimal Value!");
            return -1;
        }
        decimalValue += decimal * pow(16, i);
    }
    return decimalValue;
}

int main() {
    int decimalValue;
    char hexValue[100];

    printf("Enter a Decimal Value: ");
    scanf("%d", &decimalValue);
    printf("Equivalent Hexadecimal Value: ");
    decimalToHexadecimal(decimalValue);

    printf("\nEnter a Hexadecimal Value: ");
    scanf("%s", hexValue);
    int value = hexadecimalToDecimal(hexValue);
    if (value != -1) {
        printf("Equivalent Decimal Value: %d", value);
    }

    return 0;
}