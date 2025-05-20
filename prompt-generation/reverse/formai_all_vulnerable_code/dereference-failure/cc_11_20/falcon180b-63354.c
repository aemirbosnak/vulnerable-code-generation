//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    unsigned char red, green, blue;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"cyan", 0, 255, 255},
    {"magenta", 255, 0, 255},
    {"gray", 128, 128, 128}
};

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *color_name = strtok(line, " \t\r\n\v\f");
        Color *color = NULL;

        for (int i = 0; i < MAX_COLORS; i++) {
            if (strcmp(colors[i].name, color_name) == 0) {
                color = &colors[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Error: Invalid color name '%s'.\n", color_name);
            continue;
        }

        char *value = strtok(NULL, " \t\r\n\v\f");
        if (value == NULL) {
            printf("Error: Missing value for color '%s'.\n", color_name);
            continue;
        }

        int value_int = atoi(value);
        if (value_int < 0 || value_int > 255) {
            printf("Error: Invalid value '%s' for color '%s'.\n", value, color_name);
            continue;
        }

        fprintf(output_file, "%s = %d\n", color_name, value_int);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}