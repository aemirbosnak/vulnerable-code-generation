//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    int remainder, quotient;
    quotient = decimalNumber;

    char hexadecimalNumber[100]; // array to store hexadecimal number

    int i = 0;

    while(quotient != 0) {
        remainder = quotient % 16; // get the remainder
        if(remainder < 10) {
            hexadecimalNumber[i] = 48 + remainder; // convert the remainder to character (0-9)
        } else {
            hexadecimalNumber[i] = 55 + remainder; // convert the remainder to character (A-F)
        }
        i++;
        quotient /= 16; // update quotient
    }

    printf("Hexadecimal Number: ");

    // printing hexadecimal number in reverse order
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
}

// Function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hexadecimalNumber[]) {
    int decimalNumber = 0;
    int hexadecimalPlaceValue = 1; // variable to store hexadecimal place value

    // finding the decimal equivalent of each hexadecimal digit
    for(int i = sizeof(hexadecimalNumber)/sizeof(hexadecimalNumber[0])-2; i >= 0; i--) {
        if(hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9') {
            decimalNumber += (hexadecimalNumber[i] - '0') * hexadecimalPlaceValue;
        } else if(hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F') {
            decimalNumber += (hexadecimalNumber[i] - 'A' + 10) * hexadecimalPlaceValue;
        } else if(hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f') {
            decimalNumber += (hexadecimalNumber[i] - 'a' + 10) * hexadecimalPlaceValue;
        }
        hexadecimalPlaceValue *= 16;
    }

    printf("Decimal Number: %d\n", decimalNumber);
}

int main() {
    int choice;
    int decimalNumber;
    char hexadecimalNumber[100];

    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the decimal number: ");
                scanf("%d", &decimalNumber);
                decimalToHexadecimal(decimalNumber);
                printf("\n");
                break;
            case 2:
                printf("Enter the hexadecimal number: ");
                scanf("%s", hexadecimalNumber);
                hexadecimalToDecimal(hexadecimalNumber);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
    } while(choice != 3);

    return 0;
}