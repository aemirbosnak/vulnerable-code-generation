//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 1000

typedef struct {
    char *name;
    char hex[8];
} color_t;

color_t colors[MAX_COLOR_NAMES];
int num_colors = 0;

void load_colors() {
    FILE *fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open colors.txt\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *name = strtok(line, ",");
        char *hex = strtok(NULL, ",");

        if (name == NULL || hex == NULL) {
            fprintf(stderr, "Error: invalid line in colors.txt\n");
            exit(1);
        }

        colors[num_colors].name = strdup(name);
        strncpy(colors[num_colors].hex, hex, sizeof(colors[num_colors].hex));
        num_colors++;
    }

    fclose(fp);
}

void print_colors() {
    printf("Available colors:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s (%s)\n", colors[i].name, colors[i].hex);
    }
}

int main(int argc, char **argv) {
    load_colors();
    print_colors();

    char input[1024];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *color_name = strtok(input, " ");
        if (color_name == NULL) {
            continue;
        }

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, color_name) == 0) {
                printf("#%s\n", colors[i].hex);
                break;
            }
        }

        if (i == num_colors) {
            printf("Invalid color name\n");
        }
    }

    return 0;
}