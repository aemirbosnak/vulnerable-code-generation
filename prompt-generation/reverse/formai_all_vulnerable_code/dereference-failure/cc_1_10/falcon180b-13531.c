//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *color_name;
    int red;
    int green;
    int blue;
} Color;

Color *parse_color(char *line) {
    Color *color = malloc(sizeof(Color));
    char *token = strtok(line, ",");
    strcpy(color->color_name, token);
    token = strtok(NULL, ",");
    color->red = atoi(token);
    token = strtok(NULL, ",");
    color->green = atoi(token);
    token = strtok(NULL, ",");
    color->blue = atoi(token);
    return color;
}

void print_color(Color *color) {
    printf("%s: %d, %d, %d\n", color->color_name, color->red, color->green, color->blue);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Color *colors = NULL;
    int num_colors = 0;

    file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Color *color = parse_color(line);
        colors = realloc(colors, sizeof(Color) * (num_colors + 1));
        colors[num_colors++] = *color;
        free(color);
    }

    fclose(file);

    for (int i = 0; i < num_colors; i++) {
        print_color(&colors[i]);
    }

    free(colors);
    return 0;
}