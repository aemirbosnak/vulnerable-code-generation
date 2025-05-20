//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_FORMATS 16

typedef struct {
    char name[16];
    char hex[8];
    char rgb[16];
} ColorFormat;

ColorFormat colorFormats[MAX_COLOR_FORMATS] = {
    {"Black", "#000000", "0,0,0"},
    {"White", "#FFFFFF", "255,255,255"},
    {"Red", "#FF0000", "255,0,0"},
    {"Green", "#00FF00", "0,255,0"},
    {"Blue", "#0000FF", "0,0,255"},
    {"Yellow", "#FFFF00", "255,255,0"},
    {"Magenta", "#FF00FF", "255,0,255"},
    {"Cyan", "#00FFFF", "0,255,255"},
    {"Orange", "#FFA500", "255,165,0"},
    {"Purple", "#800080", "128,0,128"},
    {"Gray", "#808080", "128,128,128"},
    {"Pink", "#FFC0CB", "255,192,203"},
    {"Brown", "#A52A2A", "165,42,42"},
    {"Teal", "#008080", "0,128,128"},
    {"Maroon", "#800000", "128,0,0"}
};

int main() {
    int numFormats = sizeof(colorFormats) / sizeof(ColorFormat);
    int choice;

    printf("Enter the number of the color format you want to convert to:\n");
    for (int i = 0; i < numFormats; i++) {
        printf("%d. %s\n", i + 1, colorFormats[i].name);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > numFormats) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter the color in hexadecimal format:\n");
    char hexColor[8];
    scanf("%s", hexColor);

    ColorFormat *selectedFormat = &colorFormats[choice - 1];
    char *rgbColor = (char *)malloc(16 * sizeof(char));

    sprintf(rgbColor, selectedFormat->rgb, hexColor);

    printf("The color %s in %s format is %s.\n", hexColor, selectedFormat->name, rgbColor);

    free(rgbColor);
    return 0;
}