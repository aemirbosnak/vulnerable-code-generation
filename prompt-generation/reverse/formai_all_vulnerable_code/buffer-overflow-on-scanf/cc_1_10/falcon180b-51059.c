//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    unsigned int value;
} Color;

Color colors[MAX_COLORS] = {
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
    {"darkgray", 0x404040},
    {"lightblue", 0xADD8E6},
    {"lightgreen", 0x90EE90},
    {"lightred", 0xF08080},
    {"orange", 0xFFA500},
    {"pink", 0xFFC0CB},
    {"purple", 0x800080},
    {"teal", 0x008080},
};

int main() {
    char input[100];
    int i;

    printf("Enter a color name or hex code: ");
    scanf("%s", input);

    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            printf("RGB: %06X\n", colors[i].value);
            return 0;
        }
    }

    if (strlen(input) == 7 && input[0] == '#') {
        unsigned int value = 0;
        sscanf(input + 1, "%06X", &value);
        printf("RGB: %06X\n", value);
        return 0;
    }

    printf("Invalid color.\n");
    return 1;
}