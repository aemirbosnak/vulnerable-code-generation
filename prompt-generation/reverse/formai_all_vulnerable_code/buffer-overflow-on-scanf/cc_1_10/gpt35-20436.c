//FormAI DATASET v1.0 Category: Color Code Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert integer to hexadecimal string
void decToHex(int number, char* hexString) {
    sprintf(hexString, "%X", number);
}

// Convert hexadecimal string to integer
int hexToDec(char* hexString) {
    int decimal = (int)strtol(hexString, NULL, 16);
    return decimal;
}

int main() {
    char inputColor[10];
    char outputColor[10];
    char conversionType[10];
    
    printf("Enter color code in either RGB or HEX format: ");
    scanf("%s", inputColor);
    
    printf("Do you want to convert to RGB or HEX? ");
    scanf("%s", conversionType);
    
    // Determine type of conversion and perform appropriate operation
    if (strcmp(conversionType, "RGB") == 0) {
        int red, green, blue;
        if (strlen(inputColor) == 6) {
            // Convert HEX to RGB
            red = hexToDec(strncpy(outputColor, inputColor, 2));
            green = hexToDec(strncpy(outputColor + 2, inputColor + 2, 2));
            blue = hexToDec(strncpy(outputColor + 4, inputColor + 4, 2));
            printf("RGB values are: %d, %d, %d", red, green, blue);
        } else {
            // Error: invalid input
            printf("Invalid color code format");
        }
    } else if (strcmp(conversionType, "HEX") == 0) {
        if (strlen(inputColor) == 3 || strlen(inputColor) == 6) {
            // Convert RGB to HEX
            int red, green, blue;
            sscanf(inputColor, "%02X%02X%02X", &red, &green, &blue);
            sprintf(outputColor, "%02X%02X%02X", red, green, blue);
            printf("Hex value is: #%s", outputColor);
        } else {
            // Error: invalid input
            printf("Invalid color code format");
        }
    } else {
        // Error: invalid input
        printf("Invalid conversion type");
    }
    
    return 0;
}