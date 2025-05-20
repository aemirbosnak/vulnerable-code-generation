//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define HEX_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int r, g, b;
} Color;

Color colorPalette[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Gray", 128, 128, 128},
    {"Orange", 255, 165, 0}
};

const int paletteSize = sizeof(colorPalette) / sizeof(colorPalette[0]);

void printColorPalette() {
    printf("Available Colors:\n");
    for (int i = 0; i < paletteSize; i++) {
        printf("%s -> RGB(%d, %d, %d)\n", colorPalette[i].name,
               colorPalette[i].r, colorPalette[i].g, colorPalette[i].b);
    }
}

int hexToDecimal(const char* hexString) {
    return (int)strtol(hexString, NULL, 16);
}

void hexToRgb(const char* hex, int* r, int* g, int* b) {
    if (hex[0] == '#') hex++;
    *r = hexToDecimal(hex);
    *g = hexToDecimal(hex + 2);
    *b = hexToDecimal(hex + 4);
}

void rgbToHex(int r, int g, int b, char* hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

Color* findColorByName(const char* name) {
    for (int i = 0; i < paletteSize; i++) {
        if (strcmp(colorPalette[i].name, name) == 0) {
            return &colorPalette[i];
        }
    }
    return NULL;
}

void displayColorInfo() {
    char input[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name to get its RGB values: ");
    scanf("%s", input);

    Color* color = findColorByName(input);
    if (color != NULL) {
        printf("Color %s -> RGB(%d, %d, %d)\n", color->name, 
                color->r, color->g, color->b);
    } else {
        printf("Color '%s' not found in the palette.\n", input);
    }
}

void displayRgbInfo() {
    char hex[HEX_LENGTH];
    int r, g, b;
    printf("Enter a hex color code (e.g. #FF5733): ");
    scanf("%s", hex);
    if (strlen(hex) == 7) {
        hexToRgb(hex, &r, &g, &b);
        printf("Hex %s -> RGB(%d, %d, %d)\n", hex, r, g, b);
    } else {
        printf("Invalid hex format. Please use #RRGGBB format.\n");
    }
}

void displayMenu() {
    printf("\nColor Code Converter Menu:\n");
    printf("1. Display Color Palette\n");
    printf("2. Get RGB values for a color name\n");
    printf("3. Convert hex to RGB\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printColorPalette();
                break;
            case 2:
                displayColorInfo();
                break;
            case 3:
                displayRgbInfo();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}