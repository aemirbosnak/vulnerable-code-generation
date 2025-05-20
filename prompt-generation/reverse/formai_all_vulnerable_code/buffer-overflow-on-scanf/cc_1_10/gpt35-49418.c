//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>
#define HEX_BASE 16

// Function to convert decimal to hexadecimal 
void convertToHexa(int decimal) {
    char hexa[100];
    int i = 0;
    while(decimal!=0)
    {
        int temp  = 0;
        temp = decimal % HEX_BASE;
        if(temp < 10)
        {
            hexa[i] = temp + 48;
            i++;
        }
        else
        {
            hexa[i] = temp + 55;
            i++;
        }
         decimal = decimal/HEX_BASE;
    }
    printf("\nEquivalent hexadecimal value: ");
    for(int j=i-1;j>=0;j--)
        printf("%c",hexa[j]);
}

// Function to convert hexadecimal to decimal
int convertToDecimal(char hex[]) {
    int len = 0;
    while (hex[len] != '\0')
        len++;
    int base = 1;
    int decimal = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= HEX_BASE;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= HEX_BASE;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= HEX_BASE;
        }
    }
    return decimal;
}

// Main function to convert to and from hexadecimal
int main()
{
    int decimal;
    char hexa[100];
    int choice;
    printf("Enter your choice:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter Decimal Number: ");
            scanf("%d", &decimal);
            convertToHexa(decimal);
            break;
        case 2:
            printf("Enter Hexadecimal Number: ");
            scanf("%s", hexa);
            int decimalValue = convertToDecimal(hexa);
            printf("Equivalent decimal value: %d", decimalValue);
            break;
        default:
            printf("\nError: Invalid Choice! Please choose between 1 and 2 only.\n");
            break;
    }
    return 0;
}