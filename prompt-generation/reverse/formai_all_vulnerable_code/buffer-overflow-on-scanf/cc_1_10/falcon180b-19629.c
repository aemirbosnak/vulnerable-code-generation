//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100

typedef struct {
    char *name;
    char *code;
} Color;

Color color_table[MAX_COLOR_NAMES];
int color_count = 0;

void add_color(char *name, char *code) {
    if (color_count >= MAX_COLOR_NAMES) {
        printf("Error: maximum number of colors reached.\n");
        return;
    }

    color_table[color_count].name = strdup(name);
    color_table[color_count].code = strdup(code);

    color_count++;
}

int main() {
    add_color("red", "\033[31m");
    add_color("green", "\033[32m");
    add_color("blue", "\033[34m");

    char input[100];
    while (1) {
        printf("Enter a color name or code: ");
        scanf("%s", input);

        int code_index = -1;
        for (int i = 0; i < color_count; i++) {
            if (strcmp(input, color_table[i].name) == 0) {
                code_index = i;
                break;
            }
        }

        if (code_index == -1) {
            printf("Invalid color name.\n");
        } else {
            printf("%s\n", color_table[code_index].code);
        }
    }

    return 0;
}