//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hex[]);
int decimalToHex(int decimal);

int main() {
    char hexCode[8];
    int decimalCode;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexCode);

    decimalCode = hexToDecimal(hexCode);

    if(decimalCode == -1) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Decimal equivalent: %d\n", decimalCode);
    printf("Hexadecimal equivalent: %X", decimalToHex(decimalCode));

    return 0;
}

int hexToDecimal(char hex[]) {
    int length = strlen(hex);
    int decimal = 0;
    int factor = 1;

    for(int i = length - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * factor;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * factor;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * factor;
        } else {
            return -1;
        }

        factor *= 16;
    }

    return decimal;
}

int decimalToHex(int decimal) {
    char hex[8];
    int i = 0;

    while(decimal != 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }

    int length = strlen(hex);
    char result[length];

    for(int j = length - 1; j >= 0; j--) {
        result[length - j - 1] = hex[j];
    }

    return atoi(result);
}