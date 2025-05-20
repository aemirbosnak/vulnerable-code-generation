//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"red", 0xff0000},
    {"green", 0x00ff00},
    {"blue", 0x0000ff},
    {"yellow", 0xffff00},
    {"purple", 0xff00ff},
    {"orange", 0x00ff80},
    {"pink", 0xffc0cb},
    {"brown", 0x804000},
    {"grey", 0x808080},
    {"black", 0x000000},
    {"white", 0xffffff},
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    Color *color = NULL;

    for (int i = 0; i < sizeof(colors)/sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Hex code for %s: #%06x\n", color->name, color->value);
    printf("RGB code for %s: (%d, %d, %d)\n", color->name, (color->value >> 16) & 0xff, (color->value >> 8) & 0xff, color->value & 0xff);
    printf("HSL code for %s: (%d, %d, %d)\n", color->name, 0, 0, 0); // TODO: implement HSL conversion

    return 0;
}