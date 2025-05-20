//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[100];
    int decimal = 0;
    int i = 0;
    int j = 0;
    int len = 0;

    //Prompt user for hexadecimal input
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    //Validate input
    if (strlen(hex) > 8) {
        printf("Error: Input must be 8 characters or less.\n");
        return 0;
    }

    //Convert hexadecimal to decimal
    while (hex[i]!= '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal input.\n");
            return 0;
        }
        i++;
    }

    //Convert decimal to hexadecimal
    while (decimal!= 0) {
        if (decimal % 16 < 10) {
            hex[j] = decimal % 16 + '0';
        } else {
            hex[j] = decimal % 16 + 'A';
        }
        decimal /= 16;
        j++;
    }

    //Reverse the string
    for (i = 0; i < j; i++) {
        hex[i] = hex[j - i - 1];
    }
    hex[j] = '\0';

    //Print the result
    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %d\n", decimal);

    return 0;
}