//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal digit to its decimal value
int hexValue(char hexDigit)
{
    if(hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    } else if(hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    } else if(hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    } else {
        return -1;
    }
}

// Function to convert a hex color code to its RGB values
int hexToRGB(char hexCode[], int *red, int *green, int *blue)
{
    if(strlen(hexCode) != 6) {
        return 0;
    }

    *red = hexValue(hexCode[0]) * 16 + hexValue(hexCode[1]);
    *green = hexValue(hexCode[2]) * 16 + hexValue(hexCode[3]);
    *blue = hexValue(hexCode[4]) * 16 + hexValue(hexCode[5]);

    return 1;
}

int main()
{
    char hexCode[7];
    int red, green, blue;

    // Read the hex color code from the user
    printf("Enter a hexadecimal color code (with or without the # symbol): ");
    scanf("%s", hexCode);

    // Remove the # symbol from the beginning (if present)
    if(hexCode[0] == '#') {
        memmove(hexCode, hexCode+1, strlen(hexCode));
    }

    // Convert the hex color code to its RGB values
    if(hexToRGB(hexCode, &red, &green, &blue)) {
        // Print the RGB values
        printf("The RGB values for %s are (%d, %d, %d)\n", hexCode, red, green, blue);
    } else {
        printf("Invalid hexadecimal color code: %s\n", hexCode);
    }

    return 0;
}