//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64
#define MAX_COLOR_CODE_LENGTH 7

// Define color names and their corresponding codes
struct color {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH + 1];
};

static struct color colors[] = {
    {"black", "000000"},
    {"white", "FFFFFF"},
    {"red", "FF0000"},
    {"green", "00FF00"},
    {"blue", "0000FF"},
    {"yellow", "FFFF00"},
    {"magenta", "FF00FF"},
    {"cyan", "00FFFF"},
    {"gray", "888888"},
    {"lightgray", "AAAAAA"},
    {"darkgray", "444444"},
    {"lightblue", "ADD8E6"},
    {"lightgreen", "90EE90"},
    {"lightred", "FFA07A"},
    {"lightyellow", "FFFFE0"},
    {"pink", "FFB6C1"},
    {"purple", "800080"},
    {"teal", "008080"}
};

int main(int argc, char *argv[]) {
    char input[MAX_COLOR_NAME_LENGTH + 1];
    int i;

    printf("Enter a color name: ");
    scanf("%s", input);

    // Search for the color in the list
    for (i = 0; i < sizeof(colors) / sizeof(struct color); i++) {
        if (strcmp(colors[i].name, input) == 0) {
            printf("Color code for %s: %s\n", input, colors[i].code);
            return 0;
        }
    }

    // Color not found
    printf("Color not found.\n");
    return 1;
}