//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName colorNames[MAX_COLOR_NAMES];
int numColorNames = 0;

void addColorName(char *name, int value) {
    if (numColorNames >= MAX_COLOR_NAMES) {
        printf("Error: Too many color names defined.\n");
        exit(1);
    }

    colorNames[numColorNames].name = strdup(name);
    colorNames[numColorNames].value = value;

    numColorNames++;
}

int main() {
    addColorName("red", 0xff0000);
    addColorName("green", 0x00ff00);
    addColorName("blue", 0x0000ff);

    int choice;
    printf("Enter your choice:\n1. Convert RGB to color name\n2. Convert color name to RGB\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int r, g, b;
        printf("Enter the values for red, green and blue (in hexadecimal):\n");
        scanf("%x %x %x", &r, &g, &b);

        int colorValue = (r << 16) | (g << 8) | b;

        char colorName[7] = {0};
        sprintf(colorName, "#%06x", colorValue);

        for (int i = 0; i < numColorNames; i++) {
            if (colorNames[i].value == colorValue) {
                printf("The color name for %s is %s.\n", colorName, colorNames[i].name);
                break;
            }
        }
    } else if (choice == 2) {
        char colorName[256];
        printf("Enter the color name:\n");
        scanf("%s", colorName);

        for (int i = 0; i < numColorNames; i++) {
            if (strcmp(colorNames[i].name, colorName) == 0) {
                printf("The RGB value for %s is #%06x.\n", colorName, colorNames[i].value);
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}