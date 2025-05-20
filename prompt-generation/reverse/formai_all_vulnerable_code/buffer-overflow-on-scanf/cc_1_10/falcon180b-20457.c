//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to convert hexadecimal to decimal
int hexToDec(char hex[], int size) {
    int decimal = 0;
    int i = 0;
    while (hex[i]!= '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += hex[i] - 'a' + 10;
        } else {
            return -1;
        }
        i++;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char hex[]) {
    int i = 0;
    while (decimal!= 0) {
        hex[i++] = (decimal % 16) + '0';
        if (hex[i - 1] > '9') {
            hex[i - 1] += 7;
        }
        decimal /= 16;
    }
    hex[i] = '\0';
}

// Function to reverse a string
void reverse(char str[], int size) {
    int i, j;
    char temp;
    for (i = 0, j = size - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if a string is a valid hexadecimal number
int isHex(char hex[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if ((hex[i] < '0' || hex[i] > '9') && (hex[i] < 'A' || hex[i] > 'F') && (hex[i] < 'a' || hex[i] > 'f')) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char hex[MAX_SIZE], dec[MAX_SIZE];
    int size, decimal, i;

    // Get input from user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    size = strlen(hex);

    // Check if input is a valid hexadecimal number
    if (!isHex(hex, size)) {
        printf("Invalid input.\n");
        return 0;
    }

    // Convert hexadecimal to decimal
    decimal = hexToDec(hex, size);

    // Convert decimal to hexadecimal
    decToHex(decimal, dec);

    // Reverse the hexadecimal number
    reverse(dec, strlen(dec));

    // Output the result
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", dec);

    return 0;
}