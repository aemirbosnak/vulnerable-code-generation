//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <string.h>
#include <math.h>

void convertToHex(int decimal);
void convertToDecimal(char hex[]);

int main() {
    int choice;
    printf("Welcome to Hexadecimal Converter!\n");
    printf("Enter 1 to convert decimal to hexadecimal\n");
    printf("Enter 2 to convert hexadecimal to decimal\n");
    printf("Enter 3 to exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int decimal;
            printf("\nEnter the decimal number: ");
            scanf("%d", &decimal);
            convertToHex(decimal);
            printf("\n");
            break;
        }
        case 2: {
            char hex[100];
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", hex);
            convertToDecimal(hex);
            printf("\n");
            break;
        }
        case 3: {
            printf("\nThank you for using Hexadecimal Converter!\n");
            return 0;
        }
        default: {
            printf("\nInvalid choice, try again.\n");
            main();
        }
    }
    return 0;
}

void convertToHex(int decimal) {
    int remainder, quotient, i=1, j, temp;
    char hexadecimalNum[100];

    quotient = decimal;
    while (quotient != 0) {
        temp = quotient % 16;
        if (temp < 10) {
            temp = temp + 48;
        } else {
            temp = temp + 55;
        }
        hexadecimalNum[i++] = temp;
        quotient = quotient / 16;
    }
    printf("\nThe hexadecimal value of %d is: ", decimal);
    for (j = i - 1; j > 0; j--) {
        printf("%c", hexadecimalNum[j]);
    }
}

void convertToDecimal(char hex[]) {
    int decimal = 0, len, i, j=0;
    len = strlen(hex);
    for (i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * pow(16, j);
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * pow(16, j);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * pow(16, j);
        }
        j++;
    }
    printf("\nThe decimal value of %s is: %d", hex, decimal);
}