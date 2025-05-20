//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLORS 16

typedef struct {
    char *name;
    int code;
} Color;

Color colors[MAX_COLORS] = {{"Black", 0}, {"White", 7}, {"Red", 1}, {"Green", 2}, {"Blue", 3}, {"Yellow", 4}, {"Cyan", 5}, {"Magenta", 6}, {"Gray", 8}, {"DarkGray", 1}, {"LightGray", 7}, {"Pink", 5}, {"LightGreen", 2}, {"LightBlue", 3}, {"LightCyan", 5}, {"LightMagenta", 6}};

int num_colors = sizeof(colors) / sizeof(Color);

void print_usage(void) {
    printf("Usage: color_code [color_name]\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    int color_code = -1;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_code = colors[i].code;
            break;
        }
    }

    if (color_code == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color code for %s: ", color_name);

    for (int i = 0; i < MAX_CODE_LENGTH; i++) {
        if (color_code & (1 << i)) {
            printf("%d", i + 1);
        }
    }

    printf("\n");

    return 0;
}