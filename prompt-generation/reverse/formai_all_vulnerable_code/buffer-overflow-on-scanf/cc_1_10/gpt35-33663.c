//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_COLOR_RANGE 255 // maximum value for each color component
#define HEX_DIGITS 6 // number of hexadecimal digits required to represent a color code
#define MAX_INPUT_LENGTH (HEX_DIGITS + 2) // maximum length of a color code including '#' symbol and null terminator

/*
 * Function to convert a single hexadecimal character to its equivalent decimal value
 */
int hexToDecimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return 10 + (hex - 'A');
    } else if (hex >= 'a' && hex <= 'f') {
        return 10 + (hex - 'a');
    } else {
        return -1; // invalid character
    }
}

/*
 * Function to convert a color code string to its equivalent RGB values
 */
void convertColorCode(char* colorCode, int* red, int* green, int* blue) {
    int i, decimalValue;
    for (i = 1; i <= HEX_DIGITS; i++) { // skip first '#' symbol
        decimalValue = hexToDecimal(colorCode[i]);
        if (decimalValue == -1) {
            printf("Invalid color code!\n");
            return;
        }
        switch (i) {
            case 1:
                *red = decimalValue * 16;
                break;
            case 2:
                *red += decimalValue;
                break;
            case 3:
                *green = decimalValue * 16;
                break;
            case 4:
                *green += decimalValue;
                break;
            case 5:
                *blue = decimalValue * 16;
                break;
            case 6:
                *blue += decimalValue;
                break;
        }
    }
    printf("RGB values: (%d, %d, %d)\n", *red, *green, *blue);
}

/*
 * Main function to prompt user for input and call the conversion function
 */
int main() {
    char userInput[MAX_INPUT_LENGTH];
    int red = 0, green = 0, blue = 0;
    printf("Enter a color code (e.g. #FFA500): ");
    scanf("%s", userInput);
    if (userInput[0] != '#' || strlen(userInput) != MAX_INPUT_LENGTH) {
        printf("Invalid color code!\n");
        return 1;
    }
    convertColorCode(userInput, &red, &green, &blue);
    return 0;
}