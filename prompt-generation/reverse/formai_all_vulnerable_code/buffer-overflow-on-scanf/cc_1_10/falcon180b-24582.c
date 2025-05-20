//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100

struct Color {
    char name[50];
    char code[10];
};

void addColor(struct Color *colors, int *numColors, char *name, char *code) {
    if (*numColors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strcpy(colors[*numColors].name, name);
    strcpy(colors[*numColors].code, code);

    (*numColors)++;
}

int main() {
    int numColors = 0;
    struct Color colors[MAX_COLOR_NAMES];

    addColor(colors, &numColors, "red", "#FF0000");
    addColor(colors, &numColors, "green", "#00FF00");
    addColor(colors, &numColors, "blue", "#0000FF");

    char input[100];
    while (1) {
        printf("Enter a color name or code: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < numColors; i++) {
            if (strcmp(input, colors[i].name) == 0 || strcmp(input, colors[i].code) == 0) {
                printf("Color found: %s\n", input);
                break;
            }
        }

        if (i == numColors) {
            printf("Color not found.\n");
        }
    }

    return 0;
}