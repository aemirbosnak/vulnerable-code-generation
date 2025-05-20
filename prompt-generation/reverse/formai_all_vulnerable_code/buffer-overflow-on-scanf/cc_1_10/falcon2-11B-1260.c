//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hexadecimal[16];
    int remainder;

    remainder = decimal % 16;
    switch (remainder) {
        case 0:
            strcat(hexadecimal, "0");
            break;
        case 1:
            strcat(hexadecimal, "1");
            break;
        case 2:
            strcat(hexadecimal, "2");
            break;
        case 3:
            strcat(hexadecimal, "3");
            break;
        case 4:
            strcat(hexadecimal, "4");
            break;
        case 5:
            strcat(hexadecimal, "5");
            break;
        case 6:
            strcat(hexadecimal, "6");
            break;
        case 7:
            strcat(hexadecimal, "7");
            break;
        case 8:
            strcat(hexadecimal, "8");
            break;
        case 9:
            strcat(hexadecimal, "9");
            break;
        case 10:
            strcat(hexadecimal, "A");
            break;
        case 11:
            strcat(hexadecimal, "B");
            break;
        case 12:
            strcat(hexadecimal, "C");
            break;
        case 13:
            strcat(hexadecimal, "D");
            break;
        case 14:
            strcat(hexadecimal, "E");
            break;
        case 15:
            strcat(hexadecimal, "F");
            break;
    }

    decimal /= 16;
    decimalToHexadecimal(decimal);
}

int main() {
    int decimal;
    char hexadecimal[16];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToHexadecimal(decimal);
    printf("Hexadecimal equivalent: %s\n", hexadecimal);

    return 0;
}