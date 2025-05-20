//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int dec = 0;
    int i = 0;

    while (hex[i]!= '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return -1;
        }
        i++;
    }

    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[]) {
    char temp[MAX_LENGTH];
    int i = 0;

    while (dec > 0) {
        int rem = dec % 16;

        if (rem >= 10) {
            temp[i] = rem + 'A' - 10;
        } else {
            temp[i] = rem + '0';
        }

        i++;
        dec /= 16;
    }

    for (int j = i - 1; j >= 0; j--) {
        hex[j] = temp[j];
    }
    hex[i] = '\0';
}

int main() {
    char hex[MAX_LENGTH];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    dec = hexToDec(hex);

    if (dec == -1) {
        return 1;
    }

    printf("Decimal equivalent: %d\n", dec);

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    decToHex(dec, hex);

    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}