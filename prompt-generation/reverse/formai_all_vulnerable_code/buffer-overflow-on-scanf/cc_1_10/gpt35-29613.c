//FormAI DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void hexToRGB(char* hexValue);
void RGBTohex(int red, int green, int blue);

int main() {
    char input[8];
    int choice, red, green, blue;

    printf("Welcome to Color Code Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert HEX color code to RGB\n");
    printf("2. Convert RGB values to HEX color code\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter HEX value: ");
            scanf("%s", input);
            hexToRGB(input);
            break;
        case 2:
            printf("Enter Red value (0-255): ");
            scanf("%d", &red);
            printf("Enter Green value (0-255): ");
            scanf("%d", &green);
            printf("Enter Blue value (0-255): ");
            scanf("%d", &blue);
            RGBTohex(red, green, blue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

void hexToRGB(char* hexValue) {
    long int decimalValue, rem, red, green, blue;

    decimalValue = strtol(hexValue, NULL, 16);

    // Extracting Red, Green, and Blue values from decimal value
    red = decimalValue / (256 * 256);
    rem = decimalValue % (256 * 256);
    green = rem / 256;
    blue = rem % 256;

    printf("RGB value: %ld,%ld,%ld\n", red, green, blue);
}

void RGBTohex(int red, int green, int blue) {
    char hexValue[8];

    // Converting RGB values to hex code
    sprintf(hexValue, "#%02X%02X%02X", red, green, blue);

    printf("HEX value: %s\n", hexValue);
}