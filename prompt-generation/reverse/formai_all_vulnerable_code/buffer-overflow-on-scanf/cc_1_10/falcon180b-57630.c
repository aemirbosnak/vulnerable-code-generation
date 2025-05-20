//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 16

struct color {
    char name[10];
    int red;
    int green;
    int blue;
};

int main() {
    struct color colors[MAX_COLORS];
    int num_colors = 0;
    char input[100];

    printf("Welcome to the C Color Code Converter!\n");
    printf("Enter a color name (e.g. red, blue, green) or type 'quit' to exit:\n");

    while (fgets(input, sizeof(input), stdin)) {
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Convert input to uppercase
        for (int i = 0; input[i]!= '\0'; i++) {
            input[i] = toupper(input[i]);
        }

        // Check if color already exists
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, input) == 0) {
                printf("Color '%s' already exists!\n", input);
                break;
            }
        }

        // Add new color
        if (num_colors < MAX_COLORS) {
            strcpy(colors[num_colors].name, input);
            printf("Enter the red value for '%s':\n", input);
            scanf("%d", &colors[num_colors].red);
            printf("Enter the green value for '%s':\n", input);
            scanf("%d", &colors[num_colors].green);
            printf("Enter the blue value for '%s':\n", input);
            scanf("%d", &colors[num_colors].blue);
            num_colors++;
        }
    }

    printf("\nColor codes:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("'%s': #%02X%02X%02X\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
    }

    return 0;
}