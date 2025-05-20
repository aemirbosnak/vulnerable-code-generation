//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color* createColor(char* name, int red, int green, int blue) {
    Color* color = (Color*) malloc(sizeof(Color));
    strncpy(color->name, name, MAX_COLOR_NAME_LENGTH);
    color->red = red;
    color->green = green;
    color->blue = blue;
    return color;
}

int getColorIndex(Color* colors, int numColors, char* name) {
    for (int i = 0; i < numColors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void printColor(Color color) {
    printf("%s: %d, %d, %d\n", color.name, color.red, color.green, color.blue);
}

int main() {
    Color colors[] = {
        createColor("red", 255, 0, 0),
        createColor("green", 0, 255, 0),
        createColor("blue", 0, 0, 255),
        createColor("yellow", 255, 255, 0),
        createColor("cyan", 0, 255, 255),
        createColor("magenta", 255, 0, 255)
    };
    int numColors = sizeof(colors) / sizeof(colors[0]);

    char* input;
    while (1) {
        printf("Enter a color name or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        int index = getColorIndex(colors, numColors, input);
        if (index == -1) {
            printf("Unknown color: %s\n", input);
        } else {
            printColor(colors[index]);
        }
    }

    return 0;
}