//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LEN 7

struct color_code {
    char name[MAX_COLOR_NAME_LEN];
    char hex_code[7];
};

struct color_code color_codes[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"},
    {"gray", "#808080"},
    {"light_gray", "#A9A9A9"},
    {"dark_gray", "#333333"},
    {"light_red", "#FF5555"},
    {"light_green", "#55FF55"},
    {"light_blue", "#5555FF"},
    {"pink", "#FF55FF"},
    {"light_magenta", "#FF55FF"},
    {"turquoise", "#55FFFF"},
    {"violet", "#FF55FF"},
    {"orange", "#FFA500"},
    {"beige", "#F5F5DC"}
};

int num_color_codes = sizeof(color_codes) / sizeof(struct color_code);

int main(int argc, char *argv[])
{
    char input_color[MAX_COLOR_NAME_LEN];
    char output_color[9];
    int i;

    printf("Enter a color name: ");
    scanf("%s", input_color);
    for (i = 0; i < num_color_codes; i++) {
        if (strcasecmp(input_color, color_codes[i].name) == 0) {
            strcpy(output_color, color_codes[i].hex_code);
            printf("The hex code for %s is %s\n", input_color, output_color);
            return 0;
        }
    }
    printf("Color not found\n");
    return 1;
}