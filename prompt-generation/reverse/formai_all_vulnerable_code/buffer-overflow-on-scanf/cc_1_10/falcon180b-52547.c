//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    char hex[7];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void read_color_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (i >= MAX_COLOR_NAMES) {
            printf("Error: too many colors in file\n");
            exit(1);
        }
        char *name = strtok(line, " ");
        char *hex = strtok(NULL, " ");

        if (name == NULL || hex == NULL) {
            printf("Error: invalid color format\n");
            exit(1);
        }

        colors[i].name = strdup(name);
        strcpy(colors[i].hex, hex);
        i++;
    }
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];

    printf("Enter name of color file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    read_color_file(file);
    fclose(file);

    printf("Enter a color name: ");
    scanf("%s", filename);

    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(filename, colors[i].name) == 0) {
            printf("%s\n", colors[i].hex);
            break;
        }
    }

    return 0;
}