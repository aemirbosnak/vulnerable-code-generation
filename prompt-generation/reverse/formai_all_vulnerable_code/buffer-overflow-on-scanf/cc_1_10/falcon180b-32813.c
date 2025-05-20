//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

void ConvertColor(char *colorName, int *red, int *green, int *blue) {
    if (strcmp(colorName, "red") == 0) {
        *red = 255;
        *green = 0;
        *blue = 0;
    } else if (strcmp(colorName, "green") == 0) {
        *red = 0;
        *green = 255;
        *blue = 0;
    } else if (strcmp(colorName, "blue") == 0) {
        *red = 0;
        *green = 0;
        *blue = 255;
    } else if (strcmp(colorName, "yellow") == 0) {
        *red = 255;
        *green = 255;
        *blue = 0;
    } else if (strcmp(colorName, "cyan") == 0) {
        *red = 0;
        *green = 255;
        *blue = 255;
    } else if (strcmp(colorName, "magenta") == 0) {
        *red = 255;
        *green = 0;
        *blue = 255;
    } else if (strcmp(colorName, "black") == 0) {
        *red = 0;
        *green = 0;
        *blue = 0;
    } else if (strcmp(colorName, "white") == 0) {
        *red = 255;
        *green = 255;
        *blue = 255;
    } else {
        printf("Invalid color name.\n");
        exit(1);
    }
}

void PrintColor(int red, int green, int blue) {
    printf("Color: %d, %d, %d\n", red, green, blue);
}

int main() {
    char colorName[20];
    int red, green, blue;

    printf("Enter a color name: ");
    scanf("%s", colorName);

    ConvertColor(colorName, &red, &green, &blue);
    PrintColor(red, green, blue);

    return 0;
}