//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Cyan", "00FFFF"},
    {"Magenta", "FF00FF"},
    {"Gray", "808080"},
    {"DarkGray", "A9A9A9"},
    {"LightGray", "D3D3D3"},
    {"Orange", "FFA500"},
    {"Pink", "FFC0CB"},
    {"Purple", "800080"},
    {"Teal", "008080"}
};

int numColors = sizeof(colors) / sizeof(Color);

char* getColorCode(char* colorName) {
    int i;
    for (i = 0; i < numColors; i++) {
        if (strcmp(colorName, colors[i].name) == 0) {
            return colors[i].code;
        }
    }
    return NULL;
}

int main() {
    char* colorName;
    char* colorCode;

    printf("Enter a color name: ");
    scanf("%s", colorName);

    colorCode = getColorCode(colorName);

    if (colorCode!= NULL) {
        printf("The color code for %s is %s\n", colorName, colorCode);
    } else {
        printf("Invalid color name\n");
    }

    return 0;
}