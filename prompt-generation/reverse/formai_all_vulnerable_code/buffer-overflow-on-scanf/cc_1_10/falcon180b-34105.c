//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char color_code[MAX_COLOR_CODE_LENGTH];
} Color;

Color color_table[MAX_COLOR_NAMES];

int num_colors = 0;

void init_color_table() {
    color_table[num_colors].name = "red";
    strcpy(color_table[num_colors].color_code, "#FF0000");
    num_colors++;

    color_table[num_colors].name = "green";
    strcpy(color_table[num_colors].color_code, "#00FF00");
    num_colors++;

    color_table[num_colors].name = "blue";
    strcpy(color_table[num_colors].color_code, "#0000FF");
    num_colors++;
}

int get_color_index(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(name, color_table[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    init_color_table();

    char input[MAX_COLOR_CODE_LENGTH];
    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    int index = get_color_index(input);
    if (index == -1) {
        printf("Invalid color code.\n");
    } else {
        printf("Color name: %s\n", color_table[index].name);
    }

    return 0;
}