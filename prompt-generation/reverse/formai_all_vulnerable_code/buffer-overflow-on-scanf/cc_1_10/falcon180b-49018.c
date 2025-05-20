//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char *hexadecimal) {
    int i = 0;
    char hex[10];
    while (decimal > 0) {
        hex[i] = (decimal % 16) + '0';
        if (hex[i] > '9') {
            hex[i] += 7;
        }
        i++;
        decimal /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        hexadecimal[j] = hex[i - 1 - j];
    }
    hexadecimal[i] = '\0';
}

// Function to convert hexadecimal to decimal
int hexToDec(char *hexadecimal) {
    int decimal = 0;
    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        if (isdigit(hexadecimal[i])) {
            decimal = (decimal * 16) + (hexadecimal[i] - '0');
        } else if (isupper(hexadecimal[i])) {
            decimal = (decimal * 16) + (hexadecimal[i] - 'A' + 10);
        } else if (islower(hexadecimal[i])) {
            decimal = (decimal * 16) + (hexadecimal[i] - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hexadecimal[i]);
            return -1;
        }
    }
    return decimal;
}

int main() {
    char input[100];
    char hexadecimal[100];
    int decimal = 0;
    int length = 0;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            printf("Invalid decimal character: %c\n", input[i]);
            return -1;
        }
    }

    decimal = atoi(input);

    decToHex(decimal, hexadecimal);

    printf("Hexadecimal representation: %s\n", hexadecimal);

    int decFromHex = hexToDec(hexadecimal);

    if (decFromHex == -1) {
        return -1;
    }

    printf("Decimal representation: %d\n", decFromHex);

    return 0;
}