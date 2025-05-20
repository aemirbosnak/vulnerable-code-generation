//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_HEX_VALUE 15

typedef struct {
    char* name;
    char* hex;
} Color;

Color colors[] = {
    {"red", "#FF0000"},
    {"orange", "#FFA500"},
    {"yellow", "#FFFF00"},
    {"green", "#008000"},
    {"blue", "#0000FF"},
    {"purple", "#800080"},
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"gray", "#808080"},
    {"lightgray", "#D3D3D3"},
    {"darkgray", "#A9A9A9"},
    {"lightblue", "#ADD8E6"},
    {"lightgreen", "#90EE90"},
    {"lightyellow", "#FFEFD6"},
    {"pink", "#FFC0CB"},
    {"turquoise", "#40E0D0"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"brown", "#A52A2A"},
    {"navy", "#000080"},
    {"teal", "#008080"},
    {"maroon", "#800000"},
    {"olive", "#808000"}
};

int get_color_code(char* color_name) {
    int i;
    for (i = 0; i < sizeof(colors)/sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        int color_code = get_color_code(argv[1]);
        if (color_code!= -1) {
            printf("%s\n", colors[color_code].hex);
        } else {
            printf("Invalid color name\n");
        }
    } else {
        printf("Usage: %s <color name>\n", argv[0]);
    }
    return 0;
}