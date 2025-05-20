//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get the input text from the user
    char *text = malloc(100);
    printf("Enter the text you want to convert to ASCII art: ");
    scanf("%s", text);

    // Get the dimensions of the ASCII art
    int width = strlen(text);
    int height = 5;

    // Create a 2D array to store the ASCII art
    char **art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        art[i] = malloc(width * sizeof(char));
    }

    // Convert the text to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            art[i][j] = ' ';
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                art[i][j] = '-';
            } else if (j == 0 || j == width - 1) {
                art[i][j] = '|';
            } else {
                art[i][j] = text[j - 1];
            }
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < height; i++) {
        free(art[i]);
    }
    free(art);

    return 0;
}