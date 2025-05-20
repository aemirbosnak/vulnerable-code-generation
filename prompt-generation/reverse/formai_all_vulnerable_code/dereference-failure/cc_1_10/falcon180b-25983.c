//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 64

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

Color *createColor(char *name, int red, int green, int blue) {
    Color *color = (Color *) malloc(sizeof(Color));
    if (color == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strncpy(color->name, name, MAX_COLOR_NAME_LENGTH);
    color->red = red;
    color->green = green;
    color->blue = blue;
    return color;
}

void printColor(Color *color) {
    printf("Name: %s\n", color->name);
    printf("Red: %d\n", color->red);
    printf("Green: %d\n", color->green);
    printf("Blue: %d\n", color->blue);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        exit(1);
    }

    char *colorName = argv[1];
    int red, green, blue;
    if (sscanf(colorName, "#%02x%02x%02x", &red, &green, &blue) == 3) {
        printf("Hex color code: %s\n", colorName);
    } else if (sscanf(colorName, "%d,%d,%d", &red, &green, &blue) == 3) {
        printf("RGB color code: %d,%d,%d\n", red, green, blue);
    } else {
        printf("Invalid color code.\n");
        exit(1);
    }

    Color *color = createColor(colorName, red, green, blue);
    printColor(color);

    free(color);
    return 0;
}