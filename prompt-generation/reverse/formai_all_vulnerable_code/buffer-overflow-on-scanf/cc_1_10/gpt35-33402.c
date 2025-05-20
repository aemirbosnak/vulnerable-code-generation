//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>

// function to convert RGB to hexadecimal color code
void RGBtoHex(int red, int green, int blue) {
    // convert each color value to its hexadecimal equivalent
    int hexRed = red << 16;
    int hexGreen = green << 8;
    int hexBlue = blue;
    // combine the three colors into a single hexadecimal value
    int hexColor = hexRed | hexGreen | hexBlue;
    // print the hexadecimal color code
    printf("#%06X\n", hexColor);
}

// function to convert hexadecimal color code to RGB
void HexToRGB(char hexCode[]) {
    // convert the hexadecimal string to integer value
    int hexValue = 0;
    for (int i = 0; hexCode[i] != '\0'; i++) {
        if (hexCode[i] >= '0' && hexCode[i] <= '9') {
            hexValue = hexValue * 16 + (hexCode[i] - '0');
        }
        else if (hexCode[i] >= 'A' && hexCode[i] <= 'F') {
            hexValue = hexValue * 16 + (hexCode[i] - 'A' + 10);
        }
        else if (hexCode[i] >= 'a' && hexCode[i] <= 'f') {
            hexValue = hexValue * 16 + (hexCode[i] - 'a' + 10);
        }
    }
    // extract the red, green, and blue values from the hexadecimal value
    int red = (hexValue >> 16) & 255;
    int green = (hexValue >> 8) & 255;
    int blue = hexValue & 255;
    // print the RGB color values
    printf("RGB(%d,%d,%d)\n", red, green, blue);
}

int main() {
    int red, green, blue;
    char hexCode[7];
    int choice;
    do {
        printf("\nColor Code Converter Menu\n");
        printf("1. RGB to Hex\n");
        printf("2. Hex to RGB\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the RGB values (0-255):\n");
                printf("Red: ");
                scanf("%d", &red);
                printf("Green: ");
                scanf("%d", &green);
                printf("Blue: ");
                scanf("%d", &blue);
                printf("The hexadecimal color code is ");
                RGBtoHex(red, green, blue);
                break;
            case 2:
                printf("Enter the hexadecimal color code: ");
                scanf("%s", hexCode);
                printf("The RGB color values are ");
                HexToRGB(hexCode);
                break;
            case 3:
                printf("Thanks for using the Color Code Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}