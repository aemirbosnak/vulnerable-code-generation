//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"black", 0},
    {"white", 7},
    {"red", 31},
    {"green", 32},
    {"yellow", 33},
    {"blue", 34},
    {"magenta", 35},
    {"cyan", 36},
    {"gray", 37},
    {"light_red", 91},
    {"light_green", 92},
    {"light_yellow", 93},
    {"light_blue", 94},
    {"light_magenta", 95},
    {"light_cyan", 96},
    {"light_gray", 97},
    {"dark_gray", 100},
    {"light_blue", 101},
    {"light_green", 102},
    {"light_cyan", 103},
    {"light_red", 104},
    {"light_magenta", 105},
    {"light_yellow", 106},
    {"white", 107}
};

int get_color_value(char *color_name) {
    int i;
    for (i = 0; i < sizeof(color_codes)/sizeof(ColorCode); i++) {
        if (strcmp(color_codes[i].name, color_name) == 0) {
            return color_codes[i].value;
        }
    }
    return -1;
}

void print_color_code(int value, int bold) {
    if (bold) {
        printf("\033[1m");
    }
    printf("\033[38;5;%dm", value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [text] [color]\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    char *color_name = argv[2];

    int color_value = get_color_value(color_name);
    if (color_value == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    print_color_code(color_value, 1);
    printf("%s\033[0m", text);

    return 0;
}