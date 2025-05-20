//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_LENGTH 1000

typedef struct {
    char *name;
    int code;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"blue", 4},
    {"yellow", 6},
    {"magenta", 5},
    {"cyan", 3},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 12},
    {"light_yellow", 14},
    {"light_magenta", 13},
    {"light_cyan", 11},
    {"dark_gray", 15},
    {"light_gray", 7},
    {"orange", 0},
    {"pink", 5},
    {"light_blue", 1},
    {"purple", 2},
    {"teal", 4},
    {"maroon", 8},
    {"olive", 3},
    {"navy", 6},
    {"silver", 7},
    {"lime", 9},
    {"light_gray", 10},
    {"blue", 11},
    {"fuchsia", 12},
    {"gray", 13},
    {"green_yellow", 14},
    {"light_green", 15}
};

int main() {
    char input[MAX_LENGTH];
    int code = -1;

    printf("Enter a color name: ");
    scanf("%s", input);

    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(input, colors[i].name) == 0) {
            code = colors[i].code;
            break;
        }
    }

    if (code == -1) {
        printf("Invalid color name.\n");
    } else {
        printf("Color code: %d\n", code);
    }

    return 0;
}