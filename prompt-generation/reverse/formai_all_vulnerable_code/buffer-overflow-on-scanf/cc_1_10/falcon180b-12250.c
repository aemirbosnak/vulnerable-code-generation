//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH + 1];
} Color;

Color colors[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"reset", "\033[0m"}
};

int num_colors() {
    return sizeof(colors) / sizeof(Color);
}

Color *get_color(char *name) {
    int i;
    
    for (i = 0; i < num_colors(); i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }
    
    return NULL;
}

void print_color_code(Color *color) {
    printf("%s", color->code);
}

int main() {
    char input[100];
    Color *color;
    
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);
    
    printf("Enter color code (or'reset' to remove formatting): ");
    scanf("%s", input);
    
    color = get_color(input);
    
    if (color!= NULL) {
        print_color_code(color);
        printf("%s", input);
        print_color_code(get_color("reset"));
    } else {
        printf("%s", input);
    }
    
    return 0;
}