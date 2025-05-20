//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COLOR_TYPES 10
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[8];
    int red, green, blue;
} ColorType;

ColorType colorTypes[MAX_COLOR_TYPES] = {
    {"Black", "#000000", 0, 0, 0},
    {"White", "#FFFFFF", 255, 255, 255},
    {"Red", "#FF0000", 255, 0, 0},
    {"Green", "#00FF00", 0, 255, 0},
    {"Blue", "#0000FF", 0, 0, 255},
    {"Yellow", "#FFFF00", 255, 255, 0},
    {"Cyan", "#00FFFF", 0, 255, 255},
    {"Magenta", "#FF00FF", 255, 0, 255},
    {"Orange", "#FFA500", 255, 165, 0},
    {"Purple", "#800080", 128, 0, 128}
};

int numColorTypes = sizeof(colorTypes) / sizeof(ColorType);

char* convertColor(int red, int green, int blue) {
    int max = red;
    if (green > max) {
        max = green;
    }
    if (blue > max) {
        max = blue;
    }
    if (max == 0) {
        return "Black";
    }
    if (max == 255) {
        return "White";
    }
    if (red == green && green == blue) {
        return "Gray";
    }
    int index = 0;
    for (int i = 0; i < numColorTypes; i++) {
        if (colorTypes[i].red == red && colorTypes[i].green == green && colorTypes[i].blue == blue) {
            return colorTypes[i].name;
        }
    }
    sprintf(colorTypes[index].name, "Color %d", index + 1);
    sprintf(colorTypes[index].hex, "#%02X%02X%02X", red, green, blue);
    return colorTypes[index].name;
}

int main() {
    int red, green, blue;
    printf("Enter the values for red, green and blue (0-255): ");
    scanf("%d %d %d", &red, &green, &blue);
    char* colorName = convertColor(red, green, blue);
    printf("The color name for (%d, %d, %d) is %s.\n", red, green, blue, colorName);
    return 0;
}