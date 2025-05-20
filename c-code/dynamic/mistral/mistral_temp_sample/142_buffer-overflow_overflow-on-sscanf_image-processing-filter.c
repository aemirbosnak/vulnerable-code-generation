#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    char name[20];
    int r, g, b;
} Color;

void read_color(Color* color, char* line) {
    char r, g, b;
    sscanf(line, "%s %c%c%c", color->name, &r, &g, &b);
    color->r = (int)r;
    color->g = (int)g;
    color->b = (int)b;
}

void apply_filter(Color* colors, int size, char* output) {
    int i;
    for (i = 0; i < size; ++i) {
        sprintf(output, "%s %d %d %d\n", colors[i].name, colors[i].r * 2, colors[i].g * 3, colors[i].b * 4);
        strcat(output, colors[i].name);
    }
}

int main(int argc, char* argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    Color colors[10];
    int i, len;

    for (i = 1; i < argc; ++i) {
        read_color(&colors[i - 1], argv[i]);
    }

    len = sprintf(output, "Filtered colors:\n");
    apply_filter(colors, argc - 1, output + len);

    printf("%s", output);

    return 0;
}
