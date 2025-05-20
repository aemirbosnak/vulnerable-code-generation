//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int r, g, b;
} ColorMagic;

ColorMagic palette[] = {
    {"Luminescent Verdigris", 50, 205, 50},
    {"Mystic Shimmer", 105, 200, 250},
    {"Enchanted Fuchsia", 255, 105, 215},
    {"Ethereal Turquoise", 0, 255, 255},
    {"Frosted Lavender", 255, 223, 240},
    {"Radiant Sunset", 255, 165, 0},
    {"Starry Night Blue", 0, 0, 255},
    {"Whispering Willow", 205, 133, 63},
    {"Zephyr Zing", 0, 255, 255}
};

int findColorIndex(char *name) {
    int i;
    for (i = 0; i < sizeof(palette) / sizeof(ColorMagic); i++) {
        if (strcmp(palette[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printRGB(ColorMagic color) {
    printf("The RGB code for %s is (%d, %d, %d)\n", color.name, color.r, color.g, color.b);
}

int main() {
    char userInput[50];
    int index;

    printf("Welcome, Magical Painter!\n");
    printf("Please enter the name of the color from the palette: ");
    scanf("%s", userInput);

    index = findColorIndex(userInput);
    if (index == -1) {
        printf("Color not found in the magical palette.\n");
    } else {
        printRGB(palette[index]);
    }

    return 0;
}