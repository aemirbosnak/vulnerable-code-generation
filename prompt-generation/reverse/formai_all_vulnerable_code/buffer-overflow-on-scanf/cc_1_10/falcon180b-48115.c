//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} color_t;

color_t colors[MAX_COLORS] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
    {"gray", "\033[90m"},
    {"light_red", "\033[91m"}
};

void print_colors() {
    printf("Color Name\tColor Code\n");
    for (int i = 0; i < MAX_COLORS; i++) {
        printf("%-20s\t%s\n", colors[i].name, colors[i].code);
    }
}

int main() {
    int choice;
    char input[MAX_COLOR_NAME_LENGTH];

    print_colors();

    printf("\nEnter color name or code: ");
    scanf("%s", input);

    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            printf("\n%s code is %s", input, colors[i].code);
            break;
        } else if (strcmp(input, colors[i].code) == 0) {
            printf("\n%s code is %s", input, colors[i].name);
            break;
        }
    }

    return 0;
}