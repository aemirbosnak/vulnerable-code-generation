//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 100
#define MAX_COLOR_CODE_LENGTH 7

// Function prototypes
int getColorCode(char *colorName);
void printColorCode(int code);

int main() {
    char colorName[MAX_COLOR_NAME_LENGTH];
    int colorCode;

    printf("Enter a color name (maximum %d characters): ", MAX_COLOR_NAME_LENGTH - 1);
    scanf("%s", colorName);

    // Check if the color name is a known color
    colorCode = getColorCode(colorName);

    if (colorCode == -1) {
        printf("Invalid color name.\n");
    } else {
        printf("Color code for %s is ", colorName);
        printColorCode(colorCode);
        printf("\n");
    }

    return 0;
}

int getColorCode(char *colorName) {
    int code = -1;

    // Check if the color name matches a known color
    if (strcmp(colorName, "black") == 0) {
        code = 0;
    } else if (strcmp(colorName, "white") == 0) {
        code = 7;
    } else if (strcmp(colorName, "red") == 0) {
        code = 1;
    } else if (strcmp(colorName, "green") == 0) {
        code = 2;
    } else if (strcmp(colorName, "blue") == 0) {
        code = 4;
    } else if (strcmp(colorName, "yellow") == 0) {
        code = 3;
    } else if (strcmp(colorName, "magenta") == 0) {
        code = 5;
    } else if (strcmp(colorName, "cyan") == 0) {
        code = 6;
    }

    return code;
}

void printColorCode(int code) {
    char colorCode[MAX_COLOR_CODE_LENGTH];
    switch (code) {
        case 0:
            strcpy(colorCode, "30");
            break;
        case 1:
            strcpy(colorCode, "31");
            break;
        case 2:
            strcpy(colorCode, "32");
            break;
        case 3:
            strcpy(colorCode, "33");
            break;
        case 4:
            strcpy(colorCode, "34");
            break;
        case 5:
            strcpy(colorCode, "35");
            break;
        case 7:
            strcpy(colorCode, "37");
            break;
        default:
            strcpy(colorCode, "");
            break;
    }

    printf("%s", colorCode);
}