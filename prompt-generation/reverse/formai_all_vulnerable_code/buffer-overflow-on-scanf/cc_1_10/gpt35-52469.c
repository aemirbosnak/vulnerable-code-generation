//FormAI DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <string.h>

typedef struct {
    char color[20];
    int count;
} ColorCount;

int main() {
    // Initialize array to store up to 10 color choices
    ColorCount favoriteColors[10];
    int colorIndex = 0;

    // Welcome message
    printf("Welcome to your Color Manager!\n");

    while (1) {
        // Prompt user to enter a color
        char color[20];
        printf("\nEnter a color or type 'quit' to exit: ");
        scanf("%s", color);

        // Exit program if user types 'quit'
        if (strcmp(color, "quit") == 0) {
            break;
        }

        // Check if color is already in the array
        int found = 0;
        for (int i = 0; i < colorIndex; i++) {
            if (strcmp(color, favoriteColors[i].color) == 0) {
                favoriteColors[i].count++;
                found = 1;
                break;
            }
        }

        // Add color to array if not already in it
        if (!found) {
            // Check if array is full
            if (colorIndex >= 10) {
                printf("\nMaximum number of colors reached!\n");
                continue;
            }
            // Add color to array and set count to 1
            strcpy(favoriteColors[colorIndex].color, color);
            favoriteColors[colorIndex].count = 1;
            colorIndex++;
        }

        // Print updated list of favorite colors
        printf("\nYour favorite colors:\n");
        for (int i = 0; i < colorIndex; i++) {
            printf("%s (%d)\n", favoriteColors[i].color, favoriteColors[i].count);
        }
    }

    // Exit message
    printf("\nThanks for using your Color Manager!\n");

    return 0;
}