//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME 20
#define MAX_COLOR_CODE 7

typedef struct {
    char name[MAX_COLOR_NAME];
    char hex[MAX_COLOR_CODE];
} Color;

Color colorPalette[] = {
    {"Black", "#000000"},
    {"White", "#FFFFFF"},
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Cyan", "#00FFFF"},
    {"Magenta", "#FF00FF"},
    {"Silver", "#C0C0C0"},
    {"Gray", "#808080"},
    {"Maroon", "#800000"},
    {"Olive", "#808000"},
    {"DarkGreen", "#004000"},
    {"Navy", "#000080"},
    {"Purple", "#800080"},
    {"Teal", "#008080"}
};

void printColorOptions() {
    printf("Available Colors:\n");
    for (int i = 0; i < sizeof(colorPalette) / sizeof(colorPalette[0]); i++) {
        printf("  %s -> %s\n", colorPalette[i].name, colorPalette[i].hex);
    }
}

void convertNameToHex(const char *colorName) {
    for (int i = 0; i < sizeof(colorPalette) / sizeof(colorPalette[0]); i++) {
        if (strcasecmp(colorPalette[i].name, colorName) == 0) {
            printf("The HEX code for %s is %s\n", colorName, colorPalette[i].hex);
            return;
        }
    }
    printf("Color '%s' not found in palette.\n", colorName);
}

void convertHexToName(const char *hexCode) {
    for (int i = 0; i < sizeof(colorPalette) / sizeof(colorPalette[0]); i++) {
        if (strcasecmp(colorPalette[i].hex, hexCode) == 0) {
            printf("The color name for HEX code %s is %s\n", hexCode, colorPalette[i].name);
            return;
        }
    }
    printf("HEX code '%s' not found in palette.\n", hexCode);
}

int main() {
    char input[MAX_COLOR_NAME + 1];
    char option;

    printf("Welcome to the Color Code Converter!\n");
    printf("Choose an option:\n");
    printf("1. Convert Color Name to HEX Code\n");
    printf("2. Convert HEX Code to Color Name\n");
    printf("3. List Available Colors\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice (1-4): ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                printf("Enter the color name: ");
                scanf("%s", input);
                convertNameToHex(input);
                break;
            case '2':
                printf("Enter the HEX code (e.g., #FF5733): ");
                scanf("%s", input);
                convertHexToName(input);
                break;
            case '3':
                printColorOptions();
                break;
            case '4':
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose between 1 and 4.\n");
        }
    }

    return 0;
}