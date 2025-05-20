//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void hexToDecimal(char* hexNum);
void decimalToHex(int decimal);
int power(int base, int exponent);

int main() {
    char hexNum[100];
    int userChoice;
    
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("********************************************************\n");
    printf("Enter 1 to convert Hexadecimal to Decimal.\n");
    printf("Enter 2 to convert Decimal to Hexadecimal.\n");
    scanf("%d", &userChoice);
    
    if (userChoice == 1) {
        printf("Enter the Hexadecimal Number: ");
        scanf("%s", hexNum);
        hexToDecimal(hexNum);
    } else if (userChoice == 2) {
        int decimal;
        printf("Enter the Decimal Number: ");
        scanf("%d", &decimal);
        decimalToHex(decimal);
    } else {
        printf("Invalid choice! Please try again.\n");
        exit(0);
    }
    
    return 0;
}

void hexToDecimal(char* hexNum) {
    int decimal = 0;
    int len = strlen(hexNum);
    int base = 1;
    
    for (int i = len - 1; i >= 0; i--) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9') {
            decimal += (hexNum[i] - 48) * base;
            base *= 16;
        } else if (hexNum[i] >= 'a' && hexNum[i] <= 'f') {
            decimal += (hexNum[i] - 87) * base;
            base *= 16;
        } else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') {
            decimal += (hexNum[i] - 55) * base;
            base *= 16;
        } else {
            printf("Invalid Hexadecimal Number! Please try again.\n");
            exit(0);
        }
    }
    
    printf("The Decimal equivalent is: %d", decimal);
}

void decimalToHex(int decimal) {
    char hexNum[100];
    int i = 0;
    int remainder;
    
    while (decimal > 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hexNum[i] = remainder + '0';
        } else {
            hexNum[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }
    
    printf("The Hexadecimal equivalent is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexNum[j]);
    }
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}