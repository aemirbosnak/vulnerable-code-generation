//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLOR_NAMES 16

typedef struct {
    char *name;
    int value;
} Color;

Color color_names[MAX_COLOR_NAMES] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"lightred", 9},
    {"lightgreen", 10},
    {"yellow", 11},
    {"lightblue", 12},
    {"lightmagenta", 13},
    {"lightcyan", 14},
    {"lightgray", 15}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        char *color_name = strtok(line, " ");
        if (color_name == NULL) {
            printf("Error: Invalid line format in input file.\n");
            fclose(input_file);
            return 1;
        }

        Color *color = NULL;
        for (int i = 0; i < MAX_COLOR_NAMES; i++) {
            if (strcmp(color_name, color_names[i].name) == 0) {
                color = &color_names[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Error: Invalid color name %s.\n", color_name);
            fclose(input_file);
            return 1;
        }

        int value = strtol(color->value, NULL, 16);
        printf("%s = #%06X\n", color_name, value);
    }

    fclose(input_file);
    return 0;
}