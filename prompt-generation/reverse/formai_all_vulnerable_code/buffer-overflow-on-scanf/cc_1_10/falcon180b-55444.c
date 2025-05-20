//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLORS 16
#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hexcode[8];
} Color;

Color colors[MAX_COLORS] = {
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Magenta", "#FF00FF"},
    {"Cyan", "#00FFFF"},
    {"Gray", "#808080"},
    {"DarkGray", "#A9A9A9"},
    {"LightGray", "#D3D3D3"},
    {"Orange", "#FFA500"},
    {"Pink", "#FFC0CB"},
    {"Purple", "#800080"},
    {"Teal", "#008080"}
};

int main() {
    int numcolors = sizeof(colors)/sizeof(Color);
    char input[MAX_COLOR_NAME_LENGTH];
    char colorcode[9];
    int i;

    printf("Enter a color name: ");
    scanf("%s", input);

    for (i = 0; i < numcolors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            strcpy(colorcode, colors[i].hexcode);
            printf("The hex code for %s is %s\n", input, colorcode);
            break;
        }
    }

    if (i == numcolors) {
        printf("Invalid color name\n");
    }

    return 0;
}