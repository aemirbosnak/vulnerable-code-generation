//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    unsigned int hex;
} Color;

Color colors[MAX_COLORS] = {
    {"Black", 0x000000},
    {"White", 0xFFFFFF},
    {"Red", 0xFF0000},
    {"Green", 0x00FF00},
    {"Blue", 0x0000FF},
    {"Yellow", 0xFFFF00},
    {"Magenta", 0xFF00FF},
    {"Cyan", 0x00FFFF},
    {"Orange", 0xFFA500},
    {"Brown", 0xA52A2A},
    {"Gray", 0x808080},
    {"Maroon", 0x800000},
    {"Navy", 0x000080},
    {"Purple", 0x800080},
    {"Teal", 0x008080}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        exit(1);
    }

    Color *color = NULL;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(argv[1], colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        exit(1);
    }

    printf("Name: %s\n", color->name);
    printf("Hex: #%06X\n", color->hex);
    printf("RGB: %d, %d, %d\n", (color->hex >> 16) & 0xFF, (color->hex >> 8) & 0xFF, color->hex & 0xFF);
    printf("HSL: %d, %d, %d\n", 0, 0, 0); // TODO: Implement HSL conversion

    return 0;
}