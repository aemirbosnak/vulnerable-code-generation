//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7

struct ColorCode {
    char code[MAX_COLOR_CODE_LENGTH];
    int red;
    int green;
    int blue;
};

void generateRandomColorCode(struct ColorCode *colorCode) {
    int randInt;
    for (int i = 0; i < MAX_COLOR_CODE_LENGTH; i++) {
        randInt = rand() % 10;
        if (randInt == 0) {
            colorCode->code[i] = '0';
        } else {
            colorCode->code[i] = 'A' + randInt - 1;
        }
    }
    colorCode->red = rand() % 256;
    colorCode->green = rand() % 256;
    colorCode->blue = rand() % 256;
}

void printColorCode(struct ColorCode colorCode) {
    printf("Color code: %s\n", colorCode.code);
    printf("Red: %d\n", colorCode.red);
    printf("Green: %d\n", colorCode.green);
    printf("Blue: %d\n", colorCode.blue);
}

int main() {
    int numColorCodes;
    printf("Enter the number of color codes you want to generate: ");
    scanf("%d", &numColorCodes);

    struct ColorCode *colorCodes = (struct ColorCode *)malloc(numColorCodes * sizeof(struct ColorCode));

    for (int i = 0; i < numColorCodes; i++) {
        generateRandomColorCode(&colorCodes[i]);
        printColorCode(colorCodes[i]);
    }

    free(colorCodes);
    return 0;
}