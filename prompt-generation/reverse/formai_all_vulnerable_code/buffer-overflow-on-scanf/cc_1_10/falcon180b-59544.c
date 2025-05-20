//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

// Function to convert decimal to hexadecimal
void dec_to_hex(char* decimal, char* hexadecimal) {
    int i = 0, j = strlen(decimal) - 1;
    while (i < j) {
        int num = 0;
        while (i < j) {
            if (isdigit(decimal[i])) {
                num = num * 10 + (decimal[i] - '0');
                i++;
            } else {
                break;
            }
        }
        char hex = '0';
        if (num < 10) {
            hex = num + '0';
        } else if (num < 16) {
            hex = num + 'A' - 10;
        }
        hexadecimal[j--] = hex;
    }
    hexadecimal[j + 1] = '\0';
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char* hexadecimal) {
    int decimal = 0;
    while (*hexadecimal!= '\0') {
        if (isdigit(*hexadecimal)) {
            decimal = decimal * 16 + (*hexadecimal - '0');
        } else {
            decimal = decimal * 16 + (*hexadecimal - 'A' + 10);
        }
        hexadecimal++;
    }
    return decimal;
}

int main() {
    char decimal[MAX_INPUT_SIZE], hexadecimal[MAX_INPUT_SIZE];

    // Get decimal input from user
    printf("Enter a decimal number: ");
    scanf("%s", decimal);

    // Convert decimal to hexadecimal
    dec_to_hex(decimal, hexadecimal);

    // Display the hexadecimal output
    printf("Hexadecimal representation: %s\n", hexadecimal);

    // Get hexadecimal input from user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);

    // Convert hexadecimal to decimal
    int decimal_num = hex_to_dec(hexadecimal);

    // Display the decimal output
    printf("Decimal representation: %d\n", decimal_num);

    return 0;
}