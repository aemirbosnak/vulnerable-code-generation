//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 16

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int value;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 9},
    {"green", 10},
    {"yellow", 11},
    {"blue", 12},
    {"magenta", 13},
    {"cyan", 14},
    {"gray", 15}
};

int main() {
    int num_colors = sizeof(colors) / sizeof(Color);
    char input[MAX_COLOR_NAME_LENGTH];
    int value;

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a color name or type 'list' to see all available colors:\n");

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "list") == 0) {
            for (int i = 0; i < num_colors; i++) {
                printf("%s (%d)\n", colors[i].name, colors[i].value);
            }
        } else {
            for (int i = 0; i < num_colors; i++) {
                if (strcmp(input, colors[i].name) == 0) {
                    value = colors[i].value;
                    break;
                }
            }

            if (value == 0) {
                printf("Invalid color name. Try again.\n");
            } else {
                printf("The color code for %s is %d.\n", input, value);
                break;
            }
        }
    }

    return 0;
}