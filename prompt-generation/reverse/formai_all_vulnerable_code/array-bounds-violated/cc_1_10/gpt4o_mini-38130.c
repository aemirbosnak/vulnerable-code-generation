//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimalValue, char *hexString) {
    int remainder, index = 0;
    char hexDigits[] = "0123456789ABCDEF";
    
    if (decimalValue == 0) {
        hexString[index++] = '0';
    } else {
        while (decimalValue != 0) {
            remainder = decimalValue % 16;
            hexString[index++] = hexDigits[remainder];
            decimalValue /= 16;
        }
    }
    
    hexString[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hexString[i];
        hexString[i] = hexString[index - i - 1];
        hexString[index - i - 1] = temp;
    }
}

void displayHexadecimalRepresentation(int decimalValue) {
    char hexString[100];
    decimalToHexadecimal(decimalValue, hexString);
    printf("Decimal: %d -> Hexadecimal: %s\n", decimalValue, hexString);
}

void readDecimalValues() {
    int choice;
    int decimalValue;

    printf("Hexadecimal Converter\n");
    printf("1. Convert a single value\n");
    printf("2. Convert multiple values\n");
    printf("3. Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal value: ");
                scanf("%d", &decimalValue);
                displayHexadecimalRepresentation(decimalValue);
                break;
            case 2:
                printf("Enter the number of values to convert: ");
                int n;
                scanf("%d", &n);
                int *values = (int *)malloc(n * sizeof(int));
                if (values == NULL) {
                    printf("Memory allocation failed!\n");
                    return;
                }
                printf("Enter %d decimal values:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &values[i]);
                }
                for (int i = 0; i < n; i++) {
                    displayHexadecimalRepresentation(values[i]);
                }
                free(values);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}

int main() {
    readDecimalValues();
    return 0;
}