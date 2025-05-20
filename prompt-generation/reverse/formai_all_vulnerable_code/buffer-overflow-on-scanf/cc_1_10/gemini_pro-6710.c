//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_NAMES_SIZE 10
#define COLOR_CODES_SIZE 10

typedef struct {
    char *name;
    char *code;
} color_t;

color_t color_names[COLOR_NAMES_SIZE] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"},
    {"orange", "#FF8C00"},
    {"brown", "#A52A2A"}
};

color_t color_codes[COLOR_CODES_SIZE] = {
    {"#000000", "black"},
    {"#FFFFFF", "white"},
    {"#FF0000", "red"},
    {"#00FF00", "green"},
    {"#0000FF", "blue"},
    {"#FFFF00", "yellow"},
    {"#FF00FF", "magenta"},
    {"#00FFFF", "cyan"},
    {"#FF8C00", "orange"},
    {"#A52A2A", "brown"}
};

char *get_color_name(char *code) {
    for (int i = 0; i < COLOR_NAMES_SIZE; i++) {
        if (strcmp(color_names[i].code, code) == 0) {
            return color_names[i].name;
        }
    }

    return NULL;
}

char *get_color_code(char *name) {
    for (int i = 0; i < COLOR_CODES_SIZE; i++) {
        if (strcmp(color_codes[i].name, name) == 0) {
            return color_codes[i].code;
        }
    }

    return NULL;
}

void print_color_info(char *name, char *code) {
    if (name == NULL || code == NULL) {
        printf("Invalid color name or code.\n");
        return;
    }

    printf("Color name: %s\n", name);
    printf("Color code: %s\n", code);
}

void convert_color_recursively(char *input, char *output, int depth) {
    if (depth == 0) {
        return;
    }

    char *name = get_color_name(input);
    char *code = get_color_code(input);

    if (name != NULL) {
        strcpy(output, code);
    } else if (code != NULL) {
        strcpy(output, name);
    } else {
        printf("Invalid color name or code.\n");
        return;
    }

    convert_color_recursively(output, input, depth - 1);
}

int main() {
    char input[100];
    char output[100];

    printf("Enter a color name or code: ");
    scanf("%s", input);

    convert_color_recursively(input, output, 10);

    print_color_info(output, input);

    return 0;
}