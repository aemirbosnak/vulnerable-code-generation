//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int hex;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 15},
    {"red", 9},
    {"green", 10},
    {"blue", 11},
    {"yellow", 14},
    {"magenta", 13},
    {"cyan", 12},
};

int main() {
    int num_colors = sizeof(colors) / sizeof(Color);
    char input[20];
    char color_name[20];
    int color_index;
    int i;

    printf("Enter a color name or hex value: ");
    scanf("%s", input);

    if (input[0] == '#') {
        // convert hex to decimal
        sscanf(input, "#%x", &i);
        for (color_index = 0; color_index < num_colors; color_index++) {
            if (i == colors[color_index].hex) {
                printf("%s\n", colors[color_index].name);
                return 0;
            }
        }
        printf("Invalid color\n");
        return 1;
    } else {
        // search for color name
        for (color_index = 0; color_index < num_colors; color_index++) {
            strcpy(color_name, colors[color_index].name);
            strcat(color_name, " ");
        }
        strcat(color_name, "none");
        printf("%s\n", color_name);
        return 0;
    }
}