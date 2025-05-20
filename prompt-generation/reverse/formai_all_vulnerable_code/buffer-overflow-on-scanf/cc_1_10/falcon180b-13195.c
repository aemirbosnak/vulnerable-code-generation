//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[10];
    char code[7];
} Color;

Color colors[MAX_COLORS] = {
    {"BLACK", "000000"},
    {"WHITE", "FFFFFF"},
    {"RED", "FF0000"},
    {"GREEN", "00FF00"},
    {"BLUE", "0000FF"},
    {"YELLOW", "FFFF00"},
    {"CYAN", "00FFFF"},
    {"MAGENTA", "FF00FF"},
    {"ORANGE", "FFA500"},
    {"PINK", "FFC0CB"},
    {"GRAY", "808080"},
    {"LIGHT_GRAY", "C0C0C0"},
    {"DARK_GRAY", "A9A9A9"},
    {"LIGHT_BLUE", "ADD8E6"},
    {"LIGHT_GREEN", "90EE90"},
    {"LIGHT_PINK", "FFB6C1"}
};

int main() {
    int choice, i;
    char input[20];

    printf("Color Code Converter\n");
    printf("Enter your choice:\n");
    printf("1. Convert color name to code\n");
    printf("2. Convert color code to name\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter color name: ");
            scanf("%s", input);

            for (i = 0; i < MAX_COLORS; i++) {
                if (strcmp(input, colors[i].name) == 0) {
                    printf("Color code: %s\n", colors[i].code);
                    break;
                }
            }

            if (i == MAX_COLORS) {
                printf("Invalid color name.\n");
            }

            break;

        case 2:
            printf("Enter color code: ");
            scanf("%s", input);

            for (i = 0; i < MAX_COLORS; i++) {
                if (strcmp(colors[i].code, input) == 0) {
                    printf("Color name: %s\n", colors[i].name);
                    break;
                }
            }

            if (i == MAX_COLORS) {
                printf("Invalid color code.\n");
            }

            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}