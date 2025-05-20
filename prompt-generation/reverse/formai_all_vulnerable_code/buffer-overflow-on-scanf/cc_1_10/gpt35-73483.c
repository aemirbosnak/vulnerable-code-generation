//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <math.h>

int hexToDec(char hex[]) {
    int length = strlen(hex);
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

void decToHex(int decimal) {
    char hex[100] = "";
    int length = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[length] = remainder + 48;
        } else {
            hex[length] = remainder + 55;
        }
        decimal /= 16;
        length++;
    }
    if (length == 0) {
        hex[length] = '0';
        length++;
    }
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = hexToDec(hex);
    printf("Decimal conversion: %d\n", decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Hexadecimal conversion: ");
    decToHex(decimal);

    return 0;
}