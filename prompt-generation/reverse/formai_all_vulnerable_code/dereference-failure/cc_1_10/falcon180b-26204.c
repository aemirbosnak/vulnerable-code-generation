//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int value;
} color_t;

color_t colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"blue", 4},
    {"cyan", 6},
    {"magenta", 5},
    {"yellow", 3},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 12},
    {"light_cyan", 14},
    {"light_magenta", 13},
    {"light_yellow", 11}
};

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <color_name> <output_file>\n", argv[0]);
        return 1;
    }

    color_t *color = NULL;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, argv[1]) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name: %s\n", argv[1]);
        return 1;
    }

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Failed to open output file: %s\n", argv[2]);
        return 1;
    }

    fprintf(fp, "#define %s 0x%02X\n", color->name, color->value);

    fclose(fp);
    printf("Color code table generated successfully!\n");

    return 0;
}