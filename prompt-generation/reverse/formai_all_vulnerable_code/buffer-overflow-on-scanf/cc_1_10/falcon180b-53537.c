//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
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

int isValidColorCode(char* code) {
    int i = 0;
    while (code[i]!= '\0') {
        if (!isdigit(code[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

struct ColorCode* createColorCode(char* code) {
    struct ColorCode* colorCode = (struct ColorCode*) malloc(sizeof(struct ColorCode));
    strncpy(colorCode->code, code, MAX_COLOR_CODE_LENGTH);
    colorCode->red = (int) strtol(colorCode->code, NULL, 16);
    colorCode->green = (int) strtol(colorCode->code + 2, NULL, 16);
    colorCode->blue = (int) strtol(colorCode->code + 4, NULL, 16);
    return colorCode;
}

void printColorCode(struct ColorCode* colorCode) {
    printf("Color Code: %s\n", colorCode->code);
    printf("Red: %d\n", colorCode->red);
    printf("Green: %d\n", colorCode->green);
    printf("Blue: %d\n", colorCode->blue);
}

int main() {
    char input[MAX_COLOR_CODE_LENGTH];
    printf("Enter a color code (in hexadecimal format): ");
    scanf("%s", input);
    if (!isValidColorCode(input)) {
        printf("Invalid color code!\n");
        return 1;
    }
    struct ColorCode* colorCode = createColorCode(input);
    printColorCode(colorCode);
    free(colorCode);
    return 0;
}