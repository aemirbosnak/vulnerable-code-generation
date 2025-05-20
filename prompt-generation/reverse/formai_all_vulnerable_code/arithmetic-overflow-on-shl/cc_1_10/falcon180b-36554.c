//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Color {
    char name[20];
    int hex;
    int r, g, b;
};

int hexToInt(char hex) {
    if (isdigit(hex)) {
        return hex - '0';
    } else {
        return toupper(hex) - 'A' + 10;
    }
}

void generateColor(struct Color *color) {
    int i;
    for (i = 0; i < 6; i++) {
        color->name[i] = rand() % 26 + 'A';
    }
    color->name[6] = '\0';
    color->hex = rand() % 16777216;
    color->r = (color->hex >> 16) & 0xFF;
    color->g = (color->hex >> 8) & 0xFF;
    color->b = color->hex & 0xFF;
}

int main() {
    int i, j, choice;
    struct Color color;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert RGB to hex\n");
    printf("2. Convert hex to RGB\n");
    printf("3. Generate random color\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter red value (0-255): ");
            scanf("%d", &color.r);
            printf("Enter green value (0-255): ");
            scanf("%d", &color.g);
            printf("Enter blue value (0-255): ");
            scanf("%d", &color.b);

            color.hex = (color.r << 16) | (color.g << 8) | color.b;

            printf("Hex code: #%06X\n", color.hex);

            break;
        case 2:
            printf("Enter hex code: ");
            scanf(" %s", color.name);

            color.hex = strtoul(color.name, NULL, 16);

            color.r = (color.hex >> 16) & 0xFF;
            color.g = (color.hex >> 8) & 0xFF;
            color.b = color.hex & 0xFF;

            printf("Red: %d\n", color.r);
            printf("Green: %d\n", color.g);
            printf("Blue: %d\n", color.b);

            break;
        case 3:
            generateColor(&color);

            printf("Hex code: #%06X\n", color.hex);
            printf("Name: %s\n", color.name);

            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}