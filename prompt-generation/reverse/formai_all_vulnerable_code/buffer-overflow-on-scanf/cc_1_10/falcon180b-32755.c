//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 1},
    {"red", 2},
    {"green", 3},
    {"blue", 4},
    {"yellow", 5},
    {"magenta", 6},
    {"cyan", 7},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 11},
    {"light_yellow", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"dark_gray", 15}
};

int main() {
    char input[100];
    int i = 0, j, k, n;

    printf("Enter a color name or 'list' to see all colors:\n");
    scanf("%s", input);

    if (strcmp(input, "list") == 0) {
        printf("Available colors:\n");
        for (j = 0; j < sizeof(colors)/sizeof(Color); j++) {
            printf("%s (%d)\n", colors[j].name, colors[j].value);
        }
        return 0;
    }

    while (i < sizeof(colors)/sizeof(Color)) {
        if (strcmp(input, colors[i].name) == 0) {
            printf("The color code for %s is %d\n", input, colors[i].value);
            return 0;
        }
        i++;
    }

    printf("Invalid color name\n");
    return 0;
}