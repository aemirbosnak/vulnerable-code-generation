//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Pixel Art Generator 3000!\n");
    printf("Now featuring extra pixels and 100% more fun!\n\n");

    // Prompt the user for their masterpiece
    int width, height;
    printf("What is the width of your masterpiece? (1-100): ");
    scanf("%d", &width);

    printf("What is the height of your masterpiece? (1-100): ");
    scanf("%d", &height);

    // Create a 2D array to store the pixel data
    char pixels[width][height];

    // Prompt the user to draw their masterpiece
    printf("Now, draw your masterpiece! (Use '.' for empty pixels and '*' for filled pixels)\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf(" %c", &pixels[i][j]);
        }
    }

    // Print the pixel art
    printf("\nBehold! Your magnificent creation:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }

    // Offer to save the masterpiece
    char filename[100];
    printf("\nWould you like to save your masterpiece? (Y/N): ");
    scanf(" %c", &filename);

    if (filename == 'Y' || filename == 'y') {
        printf("Enter a filename: ");
        scanf("%s", filename);

        // Open the file for writing
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file for writing.\n");
            return 1;
        }

        // Write the pixel data to the file
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fprintf(file, "%c", pixels[i][j]);
            }
            fprintf(file, "\n");
        }

        // Close the file
        fclose(file);

        printf("Your masterpiece has been saved to %s.\n", filename);
    } else {
        printf("No problem. Your masterpiece will live on in your memory.\n");
    }

    return 0;
}