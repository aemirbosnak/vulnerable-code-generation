//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_COLOR_NAMES 10
#define MAX_COLOR_VALUES 10

typedef struct {
    char *name;
    char *value;
} Color;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Color colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *color_name, *color_value;
        if (sscanf(line, "color %s %s", color_name, color_value) == 2) {
            if (num_colors >= MAX_COLOR_NAMES) {
                fprintf(stderr, "Too many color definitions in file\n");
                exit(1);
            }
            colors[num_colors].name = strdup(color_name);
            colors[num_colors].value = strdup(color_value);
            num_colors++;
        }
    }

    fclose(file);

    printf("Color definitions:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s = %s\n", colors[i].name, colors[i].value);
    }

    return 0;
}