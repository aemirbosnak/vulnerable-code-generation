//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to convert decimal to hexadecimal
char * decimalToHexadecimal(int decimal) {
    char * hexadecimal = (char *) malloc(sizeof(char) * 20);
    snprintf(hexadecimal, 20, "%X", decimal);
    return hexadecimal;
}

//function to convert hexadecimal to decimal
int hexadecimalToDecimal(char * hexadecimal) {
    int decimal = strtol(hexadecimal, NULL, 16);
    return decimal;
}

int main() {
    int choice, decimal;
    char * hexadecimal = (char *) malloc(sizeof(char) * 20);

    while(1) {
        printf("\n");
        printf("Enter your choice:\n");
        printf("1. Decimal to Hexadecimal Conversion\n");
        printf("2. Hexadecimal to Decimal Conversion\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the decimal number: ");
                scanf("%d", &decimal);
                hexadecimal = decimalToHexadecimal(decimal);
                printf("The hexadecimal equivalent of %d is %s\n", decimal, hexadecimal);
                break;
            case 2:
                printf("Enter the hexadecimal number: ");
                scanf("%s", hexadecimal);
                decimal = hexadecimalToDecimal(hexadecimal);
                printf("The decimal equivalent of %s is %d\n", hexadecimal, decimal);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}