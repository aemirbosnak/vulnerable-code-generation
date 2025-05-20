//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_COLORS 1000

typedef struct {
    char *name;
    int r, g, b;
} Color;

void read_colors(FILE *fp, Color *colors, int *num_colors) {
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    int r = 0, g = 0, b = 0;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        name = strtok(line, ": ");
        value = strtok(NULL, ": ");

        if (name == NULL || value == NULL) {
            printf("Invalid line: %s\n", line);
            continue;
        }

        if (strcasecmp(name, "Color") == 0) {
            r = strtol(value, NULL, 10);
            g = strtol(strtok(NULL, " "), NULL, 10);
            b = strtol(strtok(NULL, " "), NULL, 10);

            colors[i].name = strdup(name);
            colors[i].r = r;
            colors[i].g = g;
            colors[i].b = b;

            i++;
        } else {
            printf("Invalid color name: %s\n", name);
        }
    }

    *num_colors = i;
}

void print_colors(Color *colors, int num_colors) {
    for (int i = 0; i < num_colors; i++) {
        printf("%s: %d %d %d\n", colors[i].name, colors[i].r, colors[i].g, colors[i].b);
    }
}

int main() {
    FILE *fp;
    Color colors[MAX_NUM_COLORS];
    int num_colors = 0;

    fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error opening file: colors.txt\n");
        return 1;
    }

    read_colors(fp, colors, &num_colors);
    fclose(fp);

    if (num_colors == 0) {
        printf("No colors found in file.\n");
        return 1;
    }

    print_colors(colors, num_colors);

    return 0;
}