//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <math.h>

void decimalToHexadecimal(int decimalNum) {
    char hexNum[100];
    int i = 0;

    while (decimalNum != 0) {
        int remainder = decimalNum % 16;

        if (remainder < 10) {
            hexNum[i] = remainder + 48;
            i++;
        } else {
            hexNum[i] = remainder + 55;
            i++;
        }

        decimalNum /= 16;
    }

    printf("The hexadecimal number is: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
    }

    printf("\n");
}

void hexadecimalToDecimal(char hex[]) {
    int decimalNum = 0;
    int length = strlen(hex);
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimalNum += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimalNum += (hex[i] - 55) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimalNum += (hex[i] - 87) * base;
            base *= 16;
        }
    }

    printf("The decimal number is: %d\n", decimalNum);
}

int main() {
    char hexNum[100];
    int decimalNum;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    decimalToHexadecimal(decimalNum);

    printf("Enter a hexadecimal number: ");
    scanf("%s", &hexNum);
    hexadecimalToDecimal(hexNum);

    return 0;
}