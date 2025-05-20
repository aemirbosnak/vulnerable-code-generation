//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define COLOR_NAMES_LENGTH 8
#define COLOR_NAMES "0123456789ABCDEF"

struct ColorCode {
    char name[COLOR_NAMES_LENGTH];
    unsigned int code;
};

static struct ColorCode color_codes[] = {
    {"black", 0},
    {"maroon", 0x800000},
    {"green", 0x008000},
    {"olive", 0x808000},
    {"navy", 0x000080},
    {"purple", 0x800080},
    {"teal", 0x008080},
    {"gray", 0x808080},
    {"silver", 0xc0c0c0},
    {"red", 0xff0000},
    {"lime", 0x00ff00},
    {"yellow", 0xffff00},
    {"blue", 0x0000ff},
    {"fuchsia", 0xff00ff},
    {"white", 0xffffff}
};

static int color_codes_length = sizeof(color_codes) / sizeof(color_codes[0]);

unsigned int color_code_from_name(char* name) {
    for (int i = 0; i < color_codes_length; i++) {
        if (strcmp(name, color_codes[i].name) == 0) {
            return color_codes[i].code;
        }
    }
    return 0;
}

void print_color_codes() {
    for (int i = 0; i < color_codes_length; i++) {
        printf("%s: %06X\n", color_codes[i].name, color_codes[i].code);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [color_name]\n", argv[0]);
        return 1;
    }

    char* color_name = argv[1];
    unsigned int color_code = color_code_from_name(color_name);

    if (color_code == 0) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color code for %s: %s\n", color_name, "#");
    for (int i = 0; i < MAX_CODE_LENGTH; i++) {
        char hex_digit = COLOR_NAMES[(color_code >> (i * 4)) & 0xF];
        printf("%c", hex_digit);
    }
    printf("\n");

    return 0;
}