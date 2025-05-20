//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to convert a decimal number to hexadecimal */
void decToHex(int decimal)
{
    char hexNum[100];
    int i = 0;
    while (decimal != 0) {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10) {
            hexNum[i] = temp + 48;
            i++;
        }
        else {
            hexNum[i] = temp + 55;
            i++;
        }
        decimal = decimal / 16;
    }
    printf("The hexadecimal representation is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexNum[j]);
}

/* function to convert a hexadecimal number to decimal */
int hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}

int main()
{
    int option = 0;
    printf("Welcome to the Hexadecimal Converter! \n\n");
    while (option != 3) {
        printf("Please select an option: \n");
        printf("1) Decimal to Hexadecimal Conversion \n");
        printf("2) Hexadecimal to Decimal Conversion \n");
        printf("3) Exit \n");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
        case 1:
            printf("Enter a decimal number: ");
            int decimal;
            scanf("%d", &decimal);
            decToHex(decimal);
            printf("\n\n");
            break;
        case 2:
            printf("Enter a hexadecimal number: ");
            char hex[100];
            scanf("%s", &hex);
            int decimalValue = hexToDec(hex);
            printf("The decimal representation is: %d", decimalValue);
            printf("\n\n");
            break;
        case 3:
            printf("Thank you for using the Hexadecimal Converter!");
            break;
        default:
            printf("Invalid option, please try again. \n\n");
            break;
        }
    }
    return 0;
}