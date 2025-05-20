//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct color_code {
    char *name;
    int rgb;
};

int main() {
    struct color_code colors[] = {
        {"black", 0x000000},
        {"white", 0xffffff},
        {"red", 0xff0000},
        {"green", 0x00ff00},
        {"blue", 0x0000ff},
        {"yellow", 0xffff00},
        {"cyan", 0x00ffff},
        {"magenta", 0xff00ff},
        {"gray", 0x808080},
        {"grey", 0x808080},
        {"darkred", 0x8b0000},
        {"darkgreen", 0x006400},
        {"darkblue", 0x00008b},
        {"darkyellow", 0x8b8b00},
        {"darkcyan", 0x008b8b},
        {"darkmagenta", 0x8b008b},
        {"darkgray", 0xa9a9a9},
        {"darkgrey", 0xa9a9a9},
        {"lightred", 0xff5555},
        {"lightgreen", 0x55ff55},
        {"lightblue", 0x5555ff},
        {"lightyellow", 0xffff55},
        {"lightcyan", 0x55ffff},
        {"lightmagenta", 0xff55ff},
        {"lightgray", 0xd3d3d3},
        {"lightgrey", 0xd3d3d3},
        {"orange", 0xffa500},
        {"pink", 0xffc0cb},
        {"purple", 0x800080},
        {"violet", 0xee82ee},
        {"brown", 0xa52a2a},
        {"beige", 0xf5f5dc},
        {"maroon", 0x800000},
        {"olive", 0x808000},
        {"teal", 0x008080},
        {"navy", 0x000080},
        {"silver", 0xc0c0c0},
        {"lime", 0x00ff00},
        {"aquamarine", 0x7fffd4}
    };
    int num_colors = sizeof(colors) / sizeof(struct color_code);
    char input[100];

    printf("Enter a color name: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            printf("RGB value: %06x\n", colors[i].rgb);
            return 0;
        }
    }

    printf("Color not found.\n");
    return 1;
}