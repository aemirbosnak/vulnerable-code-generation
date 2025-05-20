//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 7
#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_VALUE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char value[MAX_COLOR_VALUE_LENGTH];
} Color;

Color colors[MAX_COLORS] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Purple", "FF00FF"}
};

int get_color_index(char *color_name) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int color_index;
    char input_color[MAX_COLOR_NAME_LENGTH];
    char output_color[MAX_COLOR_VALUE_LENGTH];

    printf("Enter a color name (e.g. Black, White): ");
    scanf("%s", input_color);

    color_index = get_color_index(input_color);

    if (color_index == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    strcpy(output_color, colors[color_index].value);
    printf("The %s color code is: %s\n", input_color, output_color);

    return 0;
}