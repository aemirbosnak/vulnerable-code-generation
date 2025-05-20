//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct {
    char name[20];
    int hex;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 15},
    {"red", 9},
    {"green", 10},
    {"blue", 11},
    {"yellow", 14},
    {"cyan", 12},
    {"magenta", 13},
    {"gray", 7},
    {"orange", 1}
};

int main() {
    int choice, i;
    char input[10];

    printf("Enter a color (0-9): ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < MAX_COLORS) {
        printf("Color name: %s\n", colors[choice].name);
        printf("Hex code: #%06X\n", colors[choice].hex);
    } else {
        printf("Invalid color choice\n");
    }

    printf("Do you want to convert a color code? (y/n): ");
    scanf(" %c", &input);

    if (input == 'y' || input == 'Y') {
        printf("Enter a hex color code: ");
        scanf("%s", input);

        for (i = 0; i < MAX_COLORS; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("Hex code: #%06X\n", colors[i].hex);
                break;
            }
        }

        if (i == MAX_COLORS) {
            printf("Invalid color code\n");
        }
    }

    return 0;
}