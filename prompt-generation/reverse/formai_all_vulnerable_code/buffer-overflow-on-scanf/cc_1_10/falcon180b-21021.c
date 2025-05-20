//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

struct color {
    char name[7];
    char hex[9];
};

struct color colors[MAX_COLORS] = {
    {"BLACK", "000000"},
    {"RED", "FF0000"},
    {"GREEN", "00FF00"},
    {"YELLOW", "FFFF00"},
    {"BLUE", "0000FF"},
    {"MAGENTA", "FF00FF"},
    {"CYAN", "00FFFF"},
    {"WHITE", "FFFFFF"},
    {"ORANGE", "FFA500"},
    {"PINK", "FFC0CB"},
    {"PURPLE", "800080"},
    {"GRAY", "808080"},
    {"LIGHT_BLUE", "ADD8E6"},
    {"LIGHT_GREEN", "90EE90"},
    {"LIGHT_YELLOW", "FFEFD5"},
    {"LIGHT_PINK", "FFB6C1"}
};

int main() {
    char color_name[20];
    int color_index;

    printf("Enter a color name: ");
    scanf("%s", color_name);

    color_index = -1;
    for(int i = 0; i < MAX_COLORS; i++) {
        if(strcmp(color_name, colors[i].name) == 0) {
            color_index = i;
            break;
        }
    }

    if(color_index == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color name: %s\n", colors[color_index].name);
    printf("Hex code: %s\n", colors[color_index].hex);

    return 0;
}