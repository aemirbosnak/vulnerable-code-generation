//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

struct color {
    char name[10];
    int rgb;
};

struct color colors[] = {
    {"black", 0x000000},
    {"white", 0xFFFFFF},
    {"red", 0xFF0000},
    {"green", 0x00FF00},
    {"blue", 0x0000FF},
    {"yellow", 0xFFFF00},
    {"cyan", 0x00FFFF},
    {"magenta", 0xFF00FF},
    {"gray", 0x808080},
    {"lightgray", 0xA9A9A9},
    {"darkred", 0x8B0000},
    {"darkgreen", 0x006400},
    {"darkblue", 0x00008B},
    {"darkyellow", 0xFF8C00},
    {"darkcyan", 0x008B8B},
    {"darkmagenta", 0x8B008B}
};

int main() {
    int choice, num_colors = sizeof(colors)/sizeof(colors[0]);
    char input[20];

    printf("Enter the number of colors you want to convert:\n");
    scanf("%d", &num_colors);

    printf("Enter the color names:\n");
    for (int i = 0; i < num_colors; i++) {
        scanf("%s", input);
        for (int j = 0; j < MAX_COLORS; j++) {
            if (strcmp(input, colors[j].name) == 0) {
                printf("%s = #%06X\n", input, colors[j].rgb);
                break;
            }
        }
    }

    return 0;
}