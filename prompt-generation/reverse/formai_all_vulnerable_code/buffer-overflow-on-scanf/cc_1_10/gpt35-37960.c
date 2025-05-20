//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>

void decimalToHex(int decimalNum) {
    int remainder, hex = 0, i = 1;

    while (decimalNum != 0) {
        remainder = decimalNum % 16;
        decimalNum /= 16;
        hex += remainder * i;
        i *= 10;
    }
    printf("Hexadecimal: %d\n", hex);
}

void hexToDecimal(char hex[]) {
    int decimalNum = 0, length = 0, i;
    // finding the length of the hexadecimal string
    while (hex[length] != '\0')
        length++;
    // converting hexadecimal to decimal
    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimalNum += (hex[i] - '0') * pow(16, length - 1);
            length--;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimalNum += (hex[i] - 55) * pow(16, length - 1);
            length--;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimalNum += (hex[i] - 87) * pow(16, length - 1);
            length--;
        }
    }
    printf("Decimal: %d\n", decimalNum);
}

int main() {
    int decimalNum, choice;
    char hex[100];

    printf("Enter 1 for Decimal to Hexadecimal\nEnter 2 for Hexadecimal to Decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter decimal number: ");
        scanf("%d", &decimalNum);
        decimalToHex(decimalNum);
    } else if (choice == 2) {
        printf("Enter Hexadecimal number: ");
        scanf("%s", hex);
        hexToDecimal(hex);
    }

    return 0;
}