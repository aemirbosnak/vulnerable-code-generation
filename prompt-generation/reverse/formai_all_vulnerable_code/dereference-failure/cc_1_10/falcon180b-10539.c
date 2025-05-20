//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32
#define MAX_COLOR_CODE_LENGTH 8

struct Color {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
};

void print_usage() {
    printf("Usage:./color_converter [color_name]\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    struct Color color_table[] = {
        {"red", "\033[31m"},
        {"green", "\033[32m"},
        {"yellow", "\033[33m"},
        {"blue", "\033[34m"},
        {"purple", "\033[35m"},
        {"cyan", "\033[36m"},
        {"white", "\033[37m"},
        {"reset", "\033[0m"}
    };

    struct Color *color = NULL;
    for (int i = 0; i < sizeof(color_table) / sizeof(struct Color); i++) {
        if (strcmp(color_table[i].name, color_name) == 0) {
            color = &color_table[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("Color code for %s: %s\n", color_name, color->code);
    return 0;
}