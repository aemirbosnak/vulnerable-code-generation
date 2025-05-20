//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    int code;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"lightred", 9},
    {"lightgreen", 10},
    {"yellow", 11},
    {"lightblue", 12},
    {"lightmagenta", 13},
    {"lightcyan", 14},
    {"lightgray", 15}
};

int main() {
    int choice, code;
    char input[20];

    printf("Welcome to the Post-Apocalyptic Color Code Converter!\n\n");
    printf("Enter a color name or its code to convert: ");
    scanf("%s", input);

    // Check if input is a valid color name
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            printf("The code for %s is %d.\n", input, colors[i].code);
            return 0;
        }
    }

    // Check if input is a valid color code
    if (sscanf(input, "%d", &code)!= 1 || code < 0 || code > 15) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert color code to name
    for (int i = 0; i < MAX_COLORS; i++) {
        if (colors[i].code == code) {
            printf("The name for code %d is %s.\n", code, colors[i].name);
            return 0;
        }
    }

    printf("Invalid input.\n");
    return 1;
}