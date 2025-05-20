//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 10
#define MAX_COLOR_CODES 10

typedef struct {
    char name[20];
    char code[10];
} Color;

Color colors[MAX_COLOR_NAMES] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"reset", "\033[0m"}
};

int main() {
    char input[50];
    char color_code[10];
    int color_index;

    printf("Enter a color name: ");
    scanf("%s", input);

    color_index = -1;
    for (int i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    strcpy(color_code, colors[color_index].code);
    printf("%s", color_code);

    printf("Enter some text to color: ");
    scanf("%s", input);

    printf("%s%s%s", color_code, input, colors[0].code);

    return 0;
}