//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLOR_CODES 16

typedef struct {
    char *name;
    char code[MAX_COLOR_CODES];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].code, code);

    num_colors++;
}

int main() {
    add_color("red", "\033[31m");
    add_color("green", "\033[32m");
    add_color("yellow", "\033[33m");
    add_color("blue", "\033[34m");
    add_color("magenta", "\033[35m");
    add_color("cyan", "\033[36m");
    add_color("white", "\033[37m");

    char input[1024];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        int i, j;
        for (i = 0; i < num_colors; i++) {
            for (j = 0; j < strlen(colors[i].code); j++) {
                if (input[j] == colors[i].code[j]) {
                    printf("%s", colors[i].name);
                    break;
                }
            }
        }

        for (; j < strlen(input); j++) {
            printf("%c", input[j]);
        }
        printf("\033[0m");
    }

    return 0;
}