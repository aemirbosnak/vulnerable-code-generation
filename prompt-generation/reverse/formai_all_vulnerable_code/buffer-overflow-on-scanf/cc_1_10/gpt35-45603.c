//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>

void decimalToHex(int decimalNumber);
void hexToDecimal(char hexNumber[]);

int main() {
    int choice, decimalNumber;
    char hexNumber[10];
    printf("Welcome to the peaceful Hexadecimal Converter!\n\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n\n");
    printf("Please choose an option: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nEnter the decimal number to convert: ");
            scanf("%d", &decimalNumber);
            printf("The hexadecimal equivalent of %d is ", decimalNumber);
            decimalToHex(decimalNumber);
            break;
        case 2:
            printf("\nEnter the hexadecimal number to convert: ");
            scanf("%s", hexNumber);
            hexToDecimal(hexNumber);
            break;
        default:
            printf("\nPlease enter a valid option.\n");
            return 0;
    }
    printf("\n\nHope you enjoyed the peaceful Hexadecimal Converter. Bye!\n");
    return 0;
}

void decimalToHex(int decimalNumber) {
    int quotient, remainder;
    char hexNumber[100];
    int i = 0, j;
    quotient = decimalNumber;
    while(quotient != 0) {
        remainder = quotient % 16;
        if(remainder < 10)
            hexNumber[i++] = 48 + remainder;
        else
            hexNumber[i++] = 55 + remainder;
        quotient /= 16;
    }
    for(j = i - 1; j >= 0; j--)
        printf("%c", hexNumber[j]);
}

void hexToDecimal(char hexNumber[]) {
    int i, decimalNumber = 0, digit, weight = 1;
    for(i = strlen(hexNumber) - 1; i >= 0; i--) {
        if(hexNumber[i] >= '0' && hexNumber[i] <= '9')
            digit = hexNumber[i] - '0';
        else if(hexNumber[i] >= 'a' && hexNumber[i] <= 'f')
            digit = hexNumber[i] - 'a' + 10;
        else if(hexNumber[i] >= 'A' && hexNumber[i] <= 'F')
            digit = hexNumber[i] - 'A' + 10;
        decimalNumber += digit * weight;
        weight *= 16;
    }
    printf("The decimal equivalent of %s is %d", hexNumber, decimalNumber);
}