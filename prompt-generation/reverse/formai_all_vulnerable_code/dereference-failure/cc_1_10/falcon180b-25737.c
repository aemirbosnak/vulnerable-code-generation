//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLORS 7

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS] = {{"black", 0}, {"red", 1}, {"green", 2}, {"yellow", 3}, {"blue", 4}, {"magenta", 5}, {"cyan", 6}};

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *color_name;
    int color_value;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        color_name = strtok(line, " ");
        color_value = 0;

        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(color_name, colors[i].name) == 0) {
                color_value = colors[i].value;
                break;
            }
        }

        if (color_value == 0) {
            printf("Error: Invalid color name '%s'.\n", color_name);
        } else {
            fprintf(output_file, "%.3d ", color_value);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}