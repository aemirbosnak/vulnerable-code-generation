//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_NAME 20

typedef struct {
    int r;
    int g;
    int b;
} RGB;

typedef struct {
    float c;
    float m;
    float y;
    float k;
} CMYK;

void printMenu() {
    printf("Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to CMYK\n");
    printf("4. CMYK to RGB\n");
    printf("5. Exit\n");
}

void rgbToHex(RGB rgb) {
    printf("RGB(%d, %d, %d) -> HEX: #%02X%02X%02X\n", rgb.r, rgb.g, rgb.b, rgb.r, rgb.g, rgb.b);
}

RGB hexToRgb(const char *hex) {
    RGB rgb;
    sscanf(hex, "#%02X%02X%02X", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

CMYK rgbToCmyk(RGB rgb) {
    CMYK cmyk;
    float r = rgb.r / 255.0;
    float g = rgb.g / 255.0;
    float b = rgb.b / 255.0;

    cmyk.k = 1 - fmax(fmax(r, g), b);
    if (cmyk.k < 1) {
        cmyk.c = (1 - r - cmyk.k) / (1 - cmyk.k);
        cmyk.m = (1 - g - cmyk.k) / (1 - cmyk.k);
        cmyk.y = (1 - b - cmyk.k) / (1 - cmyk.k);
    } else {
        cmyk.c = cmyk.m = cmyk.y = 0;
    }

    return cmyk;
}

RGB cmykToRgb(CMYK cmyk) {
    RGB rgb;
    rgb.r = (1 - cmyk.c) * (1 - cmyk.k) * 255;
    rgb.g = (1 - cmyk.m) * (1 - cmyk.k) * 255;
    rgb.b = (1 - cmyk.y) * (1 - cmyk.k) * 255;
    return rgb;
}

void convertInput() {
    int choice;
    RGB rgb;
    CMYK cmyk;
    char hex[8];

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter RGB values (r g b): ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
                rgbToHex(rgb);
                break;

            case 2:
                printf("Enter HEX color code: ");
                scanf("%s", hex);
                rgb = hexToRgb(hex);
                printf("HEX(%s) -> RGB(%d, %d, %d)\n", hex, rgb.r, rgb.g, rgb.b);
                break;

            case 3:
                printf("Enter RGB values (r g b): ");
                scanf("%d %d %d", &rgb.r, &rgb.g, &rgb.b);
                cmyk = rgbToCmyk(rgb);
                printf("RGB(%d, %d, %d) -> CMYK(%.2f, %.2f, %.2f, %.2f)\n", rgb.r, rgb.g, rgb.b, cmyk.c, cmyk.m, cmyk.y, cmyk.k);
                break;

            case 4:
                printf("Enter CMYK values (c m y k): ");
                scanf("%f %f %f %f", &cmyk.c, &cmyk.m, &cmyk.y, &cmyk.k);
                rgb = cmykToRgb(cmyk);
                printf("CMYK(%.2f, %.2f, %.2f, %.2f) -> RGB(%d, %d, %d)\n", cmyk.c, cmyk.m, cmyk.y, cmyk.k, rgb.r, rgb.g, rgb.b);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 5);
}

int main() {
    convertInput();
    return 0;
}