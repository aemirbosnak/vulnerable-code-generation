//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR 100
typedef struct {
    char name[MAX_COLOR];
    int r, g, b;
} Color;

Color colors[MAX_COLOR] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Pink", 255, 192, 203},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Gray", 128, 128, 128},
};

int main() {
    char strColor[MAX_COLOR];
    Color tempColor;
    int index;

    printf("Welcome to the Colorful World!\n");
    printf("Enter a color name to get its RGB code:\n");

    scanf("%s", strColor);

    for (int i = 0; i < MAX_COLOR; i++) {
        if (strcasecmp(strColor, colors[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == MAX_COLOR) {
        printf("Color '%s' not found.\n", strColor);
        return 1;
    }

    tempColor = colors[index];

    printf("The RGB code for the color '%s' is (%d, %d, %d).\n",
        tempColor.name, tempColor.r, tempColor.g, tempColor.b);

    return 0;
}