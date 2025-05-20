//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>

#define MAX_HEX_DIGITS  16

// Function to convert decimal to hexadecimal
void decToHex(long decimal, char* hexVal)
{
    int i = 0, rem;

    while (decimal != 0 && i < MAX_HEX_DIGITS) {
        rem = decimal % 16;
        if (rem > 9) {
            hexVal[i++] = (char)(rem - 10 + 'a');
        }
        else {
            hexVal[i++] = (char)(rem + '0');
        }
        decimal /= 16;
    }
    hexVal[i] = '\0';

    // Reverse the string to get the correct order
    int len = i;
    for (i = 0; i < len / 2; i++) {
        char temp = hexVal[i];
        hexVal[i] = hexVal[len - i - 1];
        hexVal[len - i - 1] = temp;
    }
}

// Function to convert hexadecimal to decimal
long hexToDec(char* hexVal)
{
    long decimal = 0;
    int len = strlen(hexVal);
    int base = 1;
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            decimal += (hexVal[i] - 48) * base;
        }
        else if (hexVal[i] >= 'a' && hexVal[i] <= 'f') {
            decimal += (hexVal[i] - 97 + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

int main()
{
    long decimal;
    char hexVal[MAX_HEX_DIGITS + 1];

    // Decimal to hexadecimal conversion
    printf("Enter decimal number: ");
    scanf("%ld", &decimal);
    decToHex(decimal, hexVal);
    printf("Hexadecimal value: %s\n", hexVal);

    // Hexadecimal to decimal conversion
    printf("Enter hexadecimal number: ");
    scanf("%s", hexVal);
    decimal = hexToDec(hexVal);
    printf("Decimal value: %ld\n", decimal);

    return 0;
}