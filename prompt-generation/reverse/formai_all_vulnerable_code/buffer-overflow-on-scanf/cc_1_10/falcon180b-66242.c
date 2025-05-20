//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 10
#define MAX_COLOR_CODE_LEN 7
#define MAX_COLOR_NAMES 16

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    char code[MAX_COLOR_CODE_LEN];
} Color;

Color colors[MAX_COLOR_NAMES] = {
    {"black", "000000"},
    {"white", "FFFFFF"},
    {"red", "FF0000"},
    {"green", "00FF00"},
    {"blue", "0000FF"},
    {"yellow", "FFFF00"},
    {"cyan", "00FFFF"},
    {"magenta", "FF00FF"},
    {"gray", "808080"},
    {"light_gray", "A9A9A9"},
    {"dark_gray", "404040"},
    {"light_red", "FF5555"},
    {"light_green", "55FF55"},
    {"light_blue", "5555FF"},
    {"light_yellow", "FFFF55"}
};

int main() {
    int num_colors;
    char input_color[MAX_COLOR_NAME_LEN];

    printf("Enter the name of the color: ");
    scanf("%s", input_color);

    num_colors = sizeof(colors) / sizeof(Color);

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(input_color, colors[i].name) == 0) {
            printf("The color code for %s is %s\n", input_color, colors[i].code);
            return 0;
        }
    }

    printf("Invalid color name\n");
    return 1;
}