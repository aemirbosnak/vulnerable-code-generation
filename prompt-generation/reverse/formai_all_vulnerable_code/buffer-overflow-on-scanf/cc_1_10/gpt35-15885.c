//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
void convertRGB(char color[]);
void convertHex(char color[]);
void convertHSL(char color[]);

int main() {
    char color[50];
    int choice;

    printf("Welcome to the Color Code Converter Program!\n\n");
    printf("1. Convert RGB color code to Hex color code\n");
    printf("2. Convert Hex color code to RGB color code\n");
    printf("3. Convert RGB color code to HSL color code\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter RGB color code in the format R,G,B: ");
            scanf("%s", color);
            convertRGB(color);
            break;
        case 2:
            printf("Enter Hex color code in the format #RRGGBB: ");
            scanf("%s", color);
            convertHex(color);
            break;
        case 3:
            printf("Enter RGB color code in the format R,G,B: ");
            scanf("%s", color);
            convertHSL(color);
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            break;
    }

    return 0;
}

// Function to convert RGB color code to Hex color code
void convertRGB(char color[]) {
    int r, g, b;

    sscanf(color, "%d,%d,%d", &r, &g, &b);
    
    char hex[8];
    sprintf(hex, "#%02X%02X%02X", r, g, b);

    printf("The RGB color code %s is equivalent to the Hex color code %s.\n", color, hex);
}

// Function to convert Hex color code to RGB color code
void convertHex(char color[]) {
    int r, g, b;

    sscanf(color, "#%02x%02x%02x", &r, &g, &b);

    printf("The Hex color code %s is equivalent to the RGB color code %d,%d,%d.\n", color, r, g, b);
}

// Function to convert RGB color code to HSL color code
void convertHSL(char color[]) {
    int r, g, b;
    double h, s, l;

    sscanf(color, "%d,%d,%d", &r, &g, &b);

    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;

    double cmax = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
    double cmin = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);
    double delta = cmax - cmin;

    // Hue calculation
    if (delta == 0) {
        h = 0;
    } else if (cmax == red) {
        h = fmod((green - blue) / delta, 6);
    } else if (cmax == green) {
        h = ((blue - red) / delta) + 2;
    } else {
        h = ((red - green) / delta) + 4;
    }

    h = h * 60;
    if (h < 0) {
        h = h + 360;
    }

    // Lightness calculation
    l = (cmax + cmin) / 2;

    // Saturation calculation
    if (delta == 0) {
        s = 0;
    } else {
        s = delta / (1 - abs(2 * l - 1));
    }

    printf("The RGB color code %s is equivalent to the HSL color code %d,%d%%,%d%%.\n", color, (int) h, (int) (s * 100), (int) (l * 100));
}