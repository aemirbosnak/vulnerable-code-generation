//FormAI DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char code[MAX_COLOR_CODE_LENGTH + 1];
    char name[MAX_COLOR_NAME_LENGTH + 1];
} Color;

Color colors[] = {
    {"#FFFFFF", "White"},
    {"#000000", "Black"},
    {"#FF0000", "Red"},
    {"#00FF00", "Green"},
    {"#0000FF", "Blue"},
    {"#FFFF00", "Yellow"},
    {"#800080", "Purple"},
    {"#FF00FF", "Magenta"},
    {"#00FFFF", "Cyan"}
};

int isValidColorCode(char* colorCode) {
    int length = strlen(colorCode);
    if (length != MAX_COLOR_CODE_LENGTH || colorCode[0] != '#') {
        return 0;
    }
    for (int i = 1; i < length; i++) {
        if ((colorCode[i] >= '0' && colorCode[i] <= '9') || (colorCode[i] >= 'A' && colorCode[i] <= 'F')) {
            continue;
        }
        return 0;
    }
    return 1;
}

void convertColorCodeToName(char* colorCode) {
    if (!isValidColorCode(colorCode)) {
        printf("Invalid color code!\n");
        return;
    }
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].code, colorCode) == 0) {
            printf("The color name for %s is %s\n", colorCode, colors[i].name);
            return;
        }
    }
    printf("The color code %s is not in our database.\n", colorCode);
}

void convertColorNameToCode(char* colorName) {
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, colorName) == 0) {
            printf("The color code for %s is %s\n", colorName, colors[i].code);
            return;
        }
    }
    printf("The color name %s is not in our database.\n", colorName);
}

int main() {
    int choice;
    char input[MAX_COLOR_CODE_LENGTH + 1];
    printf("Welcome to Color Converter!\n");
    do {
        printf("What would you like to do?\n");
        printf("1. Convert color code to name\n");
        printf("2. Convert color name to code\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Please enter the color code you would like to convert: ");
            scanf("%s", input);
            convertColorCodeToName(input);
        } else if (choice == 2) {
            printf("Please enter the color name you would like to convert: ");
            scanf("%s", input);
            convertColorNameToCode(input);
        } else if (choice == 3) {
            printf("Thank you for using Color Converter!\n");
            break;
        }
    } while (choice != 3);
    return 0;
}