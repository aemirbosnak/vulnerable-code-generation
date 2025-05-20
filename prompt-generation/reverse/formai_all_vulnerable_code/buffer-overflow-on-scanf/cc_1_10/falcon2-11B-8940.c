//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else
        return -1;
}

// Function to convert hexadecimal string to decimal
int hexToDecString(char *str) {
    int dec = 0;
    for (int i = 0; str[i]; i++) {
        dec += hexToDec(str[i]);
        dec *= 16;
    }
    return dec;
}

// Function to convert decimal to hexadecimal
char* decToHex(int dec) {
    static char hex[6] = {'0', '0', '0', '0', '0', '0'};
    if (dec < 0) {
        strcpy(hex, "-");
        dec *= -1;
    }
    if (dec == 0) {
        strcpy(hex, "0");
        return hex;
    }

    int remainder = dec % 16;
    if (remainder < 10) {
        strcpy(hex, &remainder);
    } else {
        strcpy(hex, &remainder + 1);
    }
    dec /= 16;

    strcat(hex, "0");
    if (dec < 10) {
        strcpy(hex + 2, &dec);
    } else {
        strcpy(hex + 2, &dec + 1);
    }
    return hex;
}

// Main function
int main() {
    char hex_str[6];
    int decimal = 0;

    printf("Enter the hexadecimal number: ");
    scanf("%s", hex_str);
    decimal = hexToDecString(hex_str);

    printf("The decimal equivalent is: %d\n", decimal);
    printf("The hexadecimal equivalent is: %s\n", decToHex(decimal));

    return 0;
}