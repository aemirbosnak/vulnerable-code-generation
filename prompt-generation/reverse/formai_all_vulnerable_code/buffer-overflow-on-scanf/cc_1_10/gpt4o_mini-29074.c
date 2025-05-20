//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME 50
#define MAX_HEX_CODE 8

typedef struct Color {
    char name[MAX_COLOR_NAME];
    char hex[MAX_HEX_CODE];
} Color;

Color colors[] = {
    {"Red", "#FF0000"},
    {"Green", "#00FF00"},
    {"Blue", "#0000FF"},
    {"Yellow", "#FFFF00"},
    {"Cyan", "#00FFFF"},
    {"Magenta", "#FF00FF"},
    {"White", "#FFFFFF"},
    {"Black", "#000000"},
    {"Orange", "#FFA500"},
    {"Purple", "#800080"},
    {"Pink", "#FFC0CB"},
    {"Brown", "#A52A2A"},
    {"Gray", "#808080"},
    {"Lime", "#00FF00"},
    {"Teal", "#008080"}
};

const int colorCount = sizeof(colors) / sizeof(colors[0]);

void displayWelcomeMessage() {
    printf("******************************************\n");
    printf("* Welcome to the C Color Code Converter! *\n");
    printf("******************************************\n");
}

void displayColorList() {
    printf("\nHere are some colors you can convert:\n");
    for (int i = 0; i < colorCount; i++) {
        printf("- %s\n", colors[i].name);
    }
}

void convertColorNameToHex() {
    char input[MAX_COLOR_NAME];
    printf("\nEnter the color name you want to convert to HEX: ");
    fgets(input, MAX_COLOR_NAME, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(input, colors[i].name) == 0) {
            printf("The HEX code for %s is %s\n", colors[i].name, colors[i].hex);
            return;
        }
    }
    printf("Oops! I couldn't find that color. Please try again.\n");
}

void convertHexToColorName() {
    char input[MAX_HEX_CODE];
    printf("\nEnter the HEX code you want to convert to color name: ");
    fgets(input, MAX_HEX_CODE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    for (int i = 0; i < colorCount; i++) {
        if (strcasecmp(input, colors[i].hex) == 0) {
            printf("The color name for %s is %s\n", colors[i].hex, colors[i].name);
            return;
        }
    }
    printf("Oh no! That HEX code doesn't seem to match any color. Try again!\n");
}

void menu() {
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Convert color name to HEX\n");
        printf("2. Convert HEX to color name\n");
        printf("3. Show available colors\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after the choice

        switch (choice) {
            case 1:
                convertColorNameToHex();
                break;
            case 2:
                convertHexToColorName();
                break;
            case 3:
                displayColorList();
                break;
            case 4:
                printf("Thank you for using the Color Code Converter! Goodbye! 🎨\n");
                break;
            default:
                printf("Oops! That's not a valid choice. Please try again!\n");
        }
    } while (choice != 4);
}

int main() {
    displayWelcomeMessage();
    menu();
    return 0;
}