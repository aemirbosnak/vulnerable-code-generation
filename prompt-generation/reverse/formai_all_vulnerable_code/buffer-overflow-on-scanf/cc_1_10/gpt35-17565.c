//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>

// Function to get the decimal equivalent of a hexadecimal digit
int hexDigitToDecimal(char hexDigit) {
    if(hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    }
    else if(hexDigit >= 'A' && hexDigit <= 'F') {
        return 10 + hexDigit - 'A';
    }
    else if(hexDigit >= 'a' && hexDigit <= 'f') {
        return 10 + hexDigit - 'a';
    }
    else {
        return -1; // Invalid hex digit
    }
}

// Function to convert a hexadecimal number to decimal
int hexToDec(char *hex) {
    int decimal = 0;
    int hexDigit = 0;
    int i = 0;
    while(hex[i] != '\0') {
        hexDigit = hexDigitToDecimal(hex[i]);
        if(hexDigit == -1) {
            printf("Error: Invalid hexadecimal digit '%c'\n", hex[i]);
            return -1;
        }
        decimal = decimal * 16 + hexDigit;
        i++;
    }
    return decimal;
}

// Function to print the binary equivalent of a decimal number
void decToBin(int decimal) {
    int i;
    for(i = 31; i >= 0; i--) {
        if(decimal & (1 << i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = hexToDec(hex);
    if(decimal == -1) {
        return 0;
    }
    printf("Decimal equivalent: %d\n", decimal);
    printf("Binary equivalent: ");
    decToBin(decimal);
    printf("\n");
    return 0;
}