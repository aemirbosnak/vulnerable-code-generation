//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"blue", 4},
    {"yellow", 3},
    {"magenta", 5},
    {"cyan", 6},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 12},
    {"light_yellow", 11},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_gray", 7}
};

int main() {
    int choice, color_count = 0;
    char input[50];

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color code (e.g. #ff0000 for red): ");
    scanf("%s", input);

    // Remove the # symbol from the input
    input[0] = input[1];
    input[1] = '\0';

    int red, green, blue;
    sscanf(input, "%02x%02x%02x", &red, &green, &blue);

    printf("The color code you entered corresponds to the following colors:\n");

    for (int i = 0; i < MAX_COLORS; i++) {
        if (red == colors[i].value && green == colors[i].value && blue == colors[i].value) {
            printf("%s\n", colors[i].name);
        }
    }

    printf("\nDo you want to convert another color code? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("Please enter a color code (e.g. #ff0000 for red): ");
        scanf("%s", input);

        // Remove the # symbol from the input
        input[0] = input[1];
        input[1] = '\0';

        sscanf(input, "%02x%02x%02x", &red, &green, &blue);

        printf("The color code you entered corresponds to the following colors:\n");

        for (int i = 0; i < MAX_COLORS; i++) {
            if (red == colors[i].value && green == colors[i].value && blue == colors[i].value) {
                printf("%s\n", colors[i].name);
            }
        }

        printf("\nDo you want to convert another color code? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}