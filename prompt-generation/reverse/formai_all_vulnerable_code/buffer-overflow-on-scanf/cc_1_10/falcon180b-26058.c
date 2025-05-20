//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int value;
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
    int choice, value;
    char input[100];

    printf("Welcome to the Color Code Converter 3000!\n");
    printf("Please enter the name of the color you would like to convert:\n");
    scanf("%s", input);

    value = -1;
    for (int i = 0; i < MAX_COLORS; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            value = colors[i].value;
            break;
        }
    }

    if (value == -1) {
        printf("Error: Color not found.\n");
    } else {
        printf("The color code for %s is: %d\n", input, value);
    }

    return 0;
}