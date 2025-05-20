//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char hexadecimal[]) {
    int i = 0;
    while(decimal != 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hexadecimal[i] = 48 + remainder;
        }
        else {
            hexadecimal[i] = 55 + remainder;
        }
        i++;
        decimal /= 16;
    }
    hexadecimal[i] = '\0';
    // Reverse the hexadecimal string
    int len = strlen(hexadecimal);
    for(int j = 0; j < len/2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[len - j - 1];
        hexadecimal[len - j - 1] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexadecimal[]) {
    int len = strlen(hexadecimal);
    int decimal = 0;
    int base = 1;
    for(int i = len - 1; i >= 0; i--) {
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - 48) * base;
            base *= 16;
        }
        else if(hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * base;
            base *= 16;
        }
    }
    return decimal;
}

int main() {
    int decimal;
    char hexadecimal[100];
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimalToHexadecimal(decimal, hexadecimal);
    printf("The hexadecimal equivalent of %d is %s\n", decimal, hexadecimal);
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexadecimal);
    decimal = hexadecimalToDecimal(hexadecimal);
    printf("The decimal equivalent of %s is %d\n", hexadecimal, decimal);
    return 0;
}