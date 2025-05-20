//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLORS 256

typedef struct {
    char name[32];
    unsigned int hex;
} Color;

Color colors[MAX_COLORS];
int numColors = 0;

void initColors() {
    strcpy(colors[0].name, "black");
    colors[0].hex = 0x000000;
    numColors++;

    strcpy(colors[1].name, "white");
    colors[1].hex = 0xFFFFFF;
    numColors++;

    strcpy(colors[2].name, "red");
    colors[2].hex = 0xFF0000;
    numColors++;

    strcpy(colors[3].name, "green");
    colors[3].hex = 0x00FF00;
    numColors++;

    strcpy(colors[4].name, "blue");
    colors[4].hex = 0x0000FF;
    numColors++;
}

void printColors() {
    printf("Color Name\t\tHex Value\n");
    for (int i = 0; i < numColors; i++) {
        printf("%s\t\t0x%06X\n", colors[i].name, colors[i].hex);
    }
}

int main() {
    initColors();
    printColors();

    char colorName[32];
    while (1) {
        printf("\nEnter a color name (or type 'exit' to quit): ");
        scanf("%s", colorName);

        if (strcmp(colorName, "exit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < numColors; i++) {
            if (strcmp(colors[i].name, colorName) == 0) {
                printf("\nHex value for %s: 0x%06X\n", colorName, colors[i].hex);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nColor not found!\n");
        }
    }

    return 0;
}