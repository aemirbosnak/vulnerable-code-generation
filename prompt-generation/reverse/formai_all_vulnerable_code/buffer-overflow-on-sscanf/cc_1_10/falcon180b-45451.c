//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 32

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    int value;
} Color;

Color colors[] = {
    {"BLACK", 0},
    {"RED", 1},
    {"GREEN", 2},
    {"YELLOW", 3},
    {"BLUE", 4},
    {"MAGENTA", 5},
    {"CYAN", 6},
    {"WHITE", 7}
};

int main() {
    char input[MAX_COLOR_NAME_LEN];
    int i;

    printf("Welcome to the Retro Color Code Converter!\n");
    printf("Enter a color name or code to convert:\n");
    fgets(input, MAX_COLOR_NAME_LEN, stdin);

    if (sscanf(input, "%d", &i) == 1) {
        for (int j = 0; j < sizeof(colors) / sizeof(Color); j++) {
            if (colors[j].value == i) {
                printf("The color code %d corresponds to %s.\n", i, colors[j].name);
                return 0;
            }
        }
        printf("Invalid color code.\n");
        return 1;
    }

    for (int j = 0; j < sizeof(colors) / sizeof(Color); j++) {
        if (strcmp(input, colors[j].name) == 0) {
            printf("The color name %s corresponds to code %d.\n", input, colors[j].value);
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}