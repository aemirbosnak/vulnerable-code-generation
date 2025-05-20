//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS];
int numColors = 0;

void initColors() {
    numColors = 0;
    strcpy(colors[numColors].name, "black");
    colors[numColors].value = 0x000000;
    numColors++;

    strcpy(colors[numColors].name, "white");
    colors[numColors].value = 0xFFFFFF;
    numColors++;

    strcpy(colors[numColors].name, "red");
    colors[numColors].value = 0xFF0000;
    numColors++;

    strcpy(colors[numColors].name, "green");
    colors[numColors].value = 0x00FF00;
    numColors++;

    strcpy(colors[numColors].name, "blue");
    colors[numColors].value = 0x0000FF;
    numColors++;
}

void printColors() {
    printf("Color Name\t\tValue\n");
    for (int i = 0; i < numColors; i++) {
        printf("%-20s\t0x%06X\n", colors[i].name, colors[i].value);
    }
}

int main() {
    initColors();
    printColors();

    char input[50];
    while (1) {
        printf("\nEnter a color name or value (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int value = strtol(input, NULL, 16);
        if (value!= 0) {
            for (int i = 0; i < numColors; i++) {
                if (colors[i].value == value) {
                    printf("Color Name: %s\n", colors[i].name);
                    printf("Color Value: 0x%06X\n", value);
                    break;
                }
            }
        } else {
            for (int i = 0; i < numColors; i++) {
                if (strcmp(colors[i].name, input) == 0) {
                    printf("Color Name: %s\n", colors[i].name);
                    printf("Color Value: 0x%06X\n", colors[i].value);
                    break;
                }
            }
        }
    }

    return 0;
}