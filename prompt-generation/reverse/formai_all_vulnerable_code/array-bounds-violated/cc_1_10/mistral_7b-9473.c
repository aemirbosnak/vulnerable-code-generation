//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_LENGTH 32
#define NUM_COLORS 16

typedef struct {
    char name[MAX_COLOR_LENGTH];
    unsigned int rgb;
} Color;

const Color colors[NUM_COLORS] = {
    {"red", 0xFF0000},
    {"pink", 0xFFC0CB},
    {"purple", 0x800080},
    {"deep purple", 0x4B0082},
    {"blue", 0x0000FF},
    {"green", 0x00FF00},
    {"teal", 0x008080},
    {"cyan", 0x00FFFF},
    {"magenta", 0xFF00FF},
    {"yellow", 0xFFFF00},
    {"orange", 0xFFA500},
    {"brown", 0xA52A2A},
    {"gray", 0x808080},
    {"silver", 0xC0C0C0},
    {"maroon", 0x800000}
};

int findColorIndex(const char* name) {
    for (int i = 0; i < NUM_COLORS; ++i) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char inputColor[MAX_COLOR_LENGTH];
    int index;

    printf("Welcome to the Color Love Converter!\n");
    printf("Tell me the name of the color you desire and I will convert it to an expression of my undying love.\n");

    while (1) {
        printf("\nEnter the color name: ");
        scanf("%s", inputColor);
        inputColor[strlen(inputColor) - 1] = '\0'; // Remove trailing newline character

        index = findColorIndex(inputColor);

        if (index >= 0) {
            printf("My heart beats with the passion of %s.\n", colors[index].name);
            printf("I express my love in the RGB colors of %s: R=%d, G=%d, B=%d.\n", colors[index].name,
                   (int)(colors[index].rgb >> 16), (int)(colors[index].rgb >> 8), (int)(colors[index].rgb & 0xFF));
        } else {
            printf("I'm sorry, I couldn't find the color you mentioned. Please try again.\n");
        }
    }

    return 0;
}