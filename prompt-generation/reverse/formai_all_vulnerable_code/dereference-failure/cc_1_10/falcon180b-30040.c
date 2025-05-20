//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE,
    WHITE,
    BLACK,
    NUM_COLORS = 9
};

struct color {
    char *name;
    unsigned int value;
};

static struct color colors[] = {
    {"red", 0xff0000},
    {"green", 0x00ff00},
    {"blue", 0x0000ff},
    {"yellow", 0xffff00},
    {"orange", 0xffa500},
    {"purple", 0x800080},
    {"white", 0xffffff},
    {"black", 0x000000},
    {NULL, 0}
};

unsigned int str_to_color(const char *str) {
    for (int i = 0; i < NUM_COLORS; i++) {
        if (strcmp(str, colors[i].name) == 0) {
            return colors[i].value;
        }
    }
    return 0;
}

char *color_to_str(unsigned int color) {
    for (int i = 0; i < NUM_COLORS; i++) {
        if (colors[i].value == color) {
            return colors[i].name;
        }
    }
    return "unknown";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <color>\n", argv[0]);
        return 1;
    }

    unsigned int color = str_to_color(argv[1]);
    if (color == 0) {
        fprintf(stderr, "invalid color: %s\n", argv[1]);
        return 1;
    }

    printf("color: %s (%06x)\n", color_to_str(color), color);
    return 0;
}