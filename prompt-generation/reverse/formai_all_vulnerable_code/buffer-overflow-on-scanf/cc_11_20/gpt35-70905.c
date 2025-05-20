//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void decimalToHex(int decimalInput) {
    char hexOutput[MAX_INPUT_LENGTH];
    int remainder;
    int index = 0;

    while(decimalInput > 0) {
        remainder = decimalInput % 16;
        if (remainder < 10) {
            hexOutput[index++] = 48 + remainder;
        } else {
            hexOutput[index++] = 55 + remainder;
        }
        decimalInput /= 16;
    }

    printf("Hexadecimal Conversion : ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexOutput[i]);
    }
}

void hexToDecimal(char* hexInput) {
    int decimalOutput = 0;
    int currentDigit;
    int power = strlen(hexInput) - 1;
    
    for (int i = 0; i < strlen(hexInput); i++) {
        switch (hexInput[i]) {
            case '0':
                currentDigit = 0;
                break;
            case '1':
                currentDigit = 1;
                break;
            case '2':
                currentDigit = 2;
                break;
            case '3':
                currentDigit = 3;
                break;
            case '4':
                currentDigit = 4;
                break;
            case '5':
                currentDigit = 5;
                break;
            case '6':
                currentDigit = 6;
                break;
            case '7':
                currentDigit = 7;
                break;
            case '8':
                currentDigit = 8;
                break;
            case '9':
                currentDigit = 9;
                break;
            case 'A':
            case 'a':
                currentDigit = 10;
                break;
            case 'B':
            case 'b':
                currentDigit = 11;
                break;
            case 'C':
            case 'c':
                currentDigit = 12;
                break;
            case 'D':
            case 'd':
                currentDigit = 13;
                break;
            case 'E':
            case 'e':
                currentDigit = 14;
                break;
            case 'F':
            case 'f':
                currentDigit = 15;
                break;

            default:
                printf("Invalid Input\n");
                return;
        }

        decimalOutput += currentDigit * pow(16, power--);
    }

    printf("Decimal Conversion : %d\n", decimalOutput);    
}

int main() {
    int choice;
    char input[MAX_INPUT_LENGTH];

    while(1) {
        printf("\nChoose an option : \n1. Decimal to Hexadecimal\n2. Hexadecimal to Decimal\n3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter decimal number: ");
                int decimalInput;
                scanf("%d", &decimalInput);
                decimalToHex(decimalInput);
                break;
            case 2:
                printf("Enter hexadecimal number: ");
                scanf("%s", input);
                hexToDecimal(input);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
    
    return 0;
}