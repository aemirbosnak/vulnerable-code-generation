//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors;

void init_colors() {
    colors[0].name = "black";
    strcpy(colors[0].code, "\033[30m");
    colors[1].name = "red";
    strcpy(colors[1].code, "\033[31m");
    colors[2].name = "green";
    strcpy(colors[2].code, "\033[32m");
    colors[3].name = "yellow";
    strcpy(colors[3].code, "\033[33m");
    colors[4].name = "blue";
    strcpy(colors[4].code, "\033[34m");
    colors[5].name = "magenta";
    strcpy(colors[5].code, "\033[35m");
    colors[6].name = "cyan";
    strcpy(colors[6].code, "\033[36m");
    colors[7].name = "white";
    strcpy(colors[7].code, "\033[37m");
    num_colors = 8;
}

void print_colors() {
    printf("Available colors:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%d. %s\n", i+1, colors[i].name);
    }
}

int get_color_index(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void convert_color_code(char *text, int color_index) {
    if (color_index >= 0 && color_index < num_colors) {
        strcat(text, colors[color_index].code);
        strcat(text, "Hello, World!");
        strcat(text, "\033[0m");
    } else {
        strcat(text, "Invalid color index");
    }
}

int main() {
    init_colors();
    print_colors();

    char input[100];
    printf("Enter a color index (1-7): ");
    scanf("%s", input);

    int color_index = get_color_index(input);
    if (color_index >= 0) {
        char output[200];
        printf("Enter text to convert: ");
        scanf("%s", output);
        convert_color_code(output, color_index);
        printf("%s\n", output);
    }

    return 0;
}