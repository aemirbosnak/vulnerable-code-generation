//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void convertRGBToHex(int, int, int);
void convertHexToRGB(char*);

// main function
int main() {
    int choice;
    printf("What type of conversion do you want to perform?\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int red, green, blue;
            printf("Enter the values for Red, Green and Blue (0-255): ");
            scanf("%d %d %d", &red, &green, &blue);
            convertRGBToHex(red, green, blue);
            break;
        }
        case 2: {
            char hex[7];
            printf("Enter the Hex value (including the # symbol): ");
            scanf("%s", hex);
            convertHexToRGB(hex);
            break;
        }
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

// function to convert RGB values to Hex code
void convertRGBToHex(int r, int g, int b) {
    char hex[7];
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    printf("HEX code: %s\n", hex);
}

// function to convert Hex code to RGB values
void convertHexToRGB(char *hex) {
    char *ptr;
    int r, g, b;
    r = strtol(hex + 1, &ptr, 16);
    g = strtol(ptr + 1, &ptr, 16);
    b = strtol(ptr + 1, NULL, 16);
    printf("RGB values: %d,%d,%d\n", r, g, b);
}