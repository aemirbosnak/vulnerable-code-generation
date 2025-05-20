//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char binary[33], decimal[33];
    int choice, length, i, j, remainder, quotient;

    printf("Welcome to the Binary Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Decimal to Binary conversion
            printf("Enter a decimal number: ");
            scanf("%s", decimal);
            length = strlen(decimal);
            for(i = length - 1, j = 0; i >= 0; i--, j++) {
                remainder = decimal[i] - '0';
                quotient = floor(remainder / 2);
                binary[j] = quotient + '0';
                remainder -= quotient * 2;
                if(remainder == 1) {
                    binary[j] = '1' + binary[j];
                }
            }
            binary[j] = '\0';
            printf("The binary equivalent is: %s\n", binary);
            break;

        case 2: // Binary to Decimal conversion
            printf("Enter a binary number: ");
            scanf("%s", binary);
            length = strlen(binary);
            for(i = 0, j = length - 1; i < length; i++, j--) {
                if(binary[i] == '1') {
                    decimal[i] = '1';
                } else {
                    decimal[i] = '0';
                }
            }
            decimal[length] = '\0';
            printf("The decimal equivalent is: %s\n", decimal);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}