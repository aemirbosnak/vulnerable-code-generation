//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>

// Function to convert hexadecimal number to decimal
int hex_to_decimal(char hexadecimal) {
    int decimal = 0;
    switch(hexadecimal) {
        case '0':
            decimal = 0;
            break;
        case '1':
            decimal = 1;
            break;
        case '2':
            decimal = 2;
            break;
        case '3':
            decimal = 3;
            break;
        case '4':
            decimal = 4;
            break;
        case '5':
            decimal = 5;
            break;
        case '6':
            decimal = 6;
            break;
        case '7':
            decimal = 7;
            break;
        case '8':
            decimal = 8;
            break;
        case '9':
            decimal = 9;
            break;
        case 'A':
            decimal = 10;
            break;
        case 'B':
            decimal = 11;
            break;
        case 'C':
            decimal = 12;
            break;
        case 'D':
            decimal = 13;
            break;
        case 'E':
            decimal = 14;
            break;
        case 'F':
            decimal = 15;
            break;
    }
    return decimal;
}

int main() {
    // Read hexadecimal number as input
    char hexadecimal[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);

    // Convert hexadecimal number to decimal using hex_to_decimal function
    int decimal = hex_to_decimal(hexadecimal[0]);
    for(int i = 1; i < 4; i++) {
        decimal += hex_to_decimal(hexadecimal[i]) * pow(16, i - 1);
    }

    // Display the result
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}