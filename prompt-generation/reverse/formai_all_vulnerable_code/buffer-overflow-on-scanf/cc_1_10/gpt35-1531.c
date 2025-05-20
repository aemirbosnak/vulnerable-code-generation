//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RGB 3

void convertToUpperCase(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }
}

int validateColorCode(char* colorCode) {
    int length = strlen(colorCode);
    if (length != 6) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isxdigit(colorCode[i])) {
            return 0;
        }
    }

    return 1;
}

void convertColorCodeToRGB(char* colorCode, int* rgbValues) {
    char* colorCodeSubstring; 
    rgbValues[0] = strtol(colorCodeSubstring = strdup(colorCode), &colorCodeSubstring, 16); 
    rgbValues[1] = strtol(colorCodeSubstring = strdup(colorCode + 2), &colorCodeSubstring, 16);
    rgbValues[2] = strtol(colorCodeSubstring = strdup(colorCode + 4), &colorCodeSubstring, 16);
}

void printColorCode(char* colorCode, int* rgbValues) {
    printf("The color code '%s' corresponds to R: %d G: %d B: %d\n", colorCode, rgbValues[0], rgbValues[1], rgbValues[2]);
}

int main() {
    char input[10];
    int rgbValues[RGB];
    do {
        printf("Please enter a color code (in format RRGGBB) or type 'exit' to quit: ");
        scanf("%s", input);

        convertToUpperCase(input);

        if (strcmp(input, "EXIT") == 0) {
            return 1;
        }

        if (!validateColorCode(input)) {
            printf("Invalid format. Please enter a valid color code.\n");
            continue;
        }

        convertColorCodeToRGB(input, rgbValues);
        printColorCode(input, rgbValues);
    } while (1);

    return 0;
}