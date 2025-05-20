//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    { "black", 0 },
    { "white", 1 },
    { "red", 2 },
    { "green", 3 },
    { "blue", 4 },
    { "yellow", 5 },
    { "magenta", 6 },
    { "cyan", 7 },
    { "gray", 8 },
    { "darkgray", 9 },
    { "lightred", 10 },
    { "lightgreen", 11 },
    { "lightblue", 12 },
    { "lightyellow", 13 },
    { "lightmagenta", 14 },
    { "lightcyan", 15 }
};

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <color_name_or_value>\n", argv[0]);
        exit(1);
    }

    char *color_name = argv[1];
    int color_value = 0;

    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_value = colors[i].value;
            break;
        }
    }

    if (color_value == 0) {
        printf("Invalid color name or value.\n");
        exit(1);
    }

    printf("Color name: %s\n", color_name);
    printf("Color value: %d\n", color_value);
    printf("RGB value: %d\n", (color_value >> 4) & 0x07);
    printf("Foreground color code: %d\n", 30 + color_value);
    printf("Background color code: %d\n", 40 + color_value);

    return 0;
}