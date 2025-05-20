//FormAI DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10

typedef struct {
    char name[20];
    int value;
} Color;

Color RED = {"RED", 0xFF0000};
Color GREEN = {"GREEN", 0x00FF00};
Color BLUE = {"BLUE", 0x0000FF};

Color* colors[3] = {&RED, &GREEN, &BLUE};

int hexToDec(char* hexCode) {
    int decCode = strtol(hexCode, NULL, 16);
    return decCode;
}

void printColor(Color* color) {
    printf("%s has a hex value of #%06X\n", color->name, color->value);
}

void printAllColors() {
    for (int i = 0; i < 3; i++) {
        printColor(colors[i]);
    }
}

Color* findColor(char* name) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(name, colors[i]->name) == 0) {
            return colors[i];
        }
    }
    return NULL;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    Color* selectedColor;

    printf("Welcome to the Color Code Converter!\n");

    while (1) {
        printf("Enter a color name or '#' followed by a 6-digit hexadecimal code: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strlen(input) - 1] = '\0';

        if (input[0] == '#') {
            if (strlen(input) != 7) {
                printf("Invalid input.\n");
                continue;
            }

            selectedColor = malloc(sizeof(Color));
            strcpy(selectedColor->name, "Selected Color");

            selectedColor->value = hexToDec(input + 1);
            printColor(selectedColor);

            free(selectedColor);
        }
        else {
            selectedColor = findColor(input);
            if (selectedColor == NULL) {
                printf("Invalid input.\n");
                continue;
            }

            printColor(selectedColor);
        }
    }

    return 0;
}