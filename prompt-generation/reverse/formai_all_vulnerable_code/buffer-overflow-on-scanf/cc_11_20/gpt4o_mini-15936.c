//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 20

// Function to create pixel art
void createPixelArt(char art[HEIGHT][WIDTH]) {
    // Fill background with spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            art[i][j] = ' ';
        }
    }

    // Create a heart shape
    for (int i = 5; i < 15; i++) {
        for (int j = 5; j < 35; j++) {
            if ((i == 5 && (j == 9 || j == 10 || j == 29 || j == 30)) ||
                (i == 6 && (j >= 7 && j <= 12) || (j >= 28 && j <= 33)) ||
                (i == 7 && (j >= 6 && j <= 13) || (j >= 27 && j <= 34)) ||
                (i == 8 && (j >= 5 && j <= 14) || (j >= 26 && j <= 35)) ||
                (i == 9 && (j >= 4 && j <= 15) || (j >= 25 && j <= 36)) ||
                (i == 10 && (j >= 3 && j <= 16) || (j >= 24 && j <= 37)) ||
                (i == 11 && (j >= 2 && j <= 17) || (j >= 23 && j <= 38)) ||
                (i == 12 && j >= 3 && j <= 18) ||
                (i == 13 && (j >= 4 && j <= 17) || (j >= 21 && j <= 22)) ||
                (i >= 14 && i <= 18 && j >= 8 && j <= 14) ||
                (i == 19 && (j >= 9 && j <= 10))) {
                art[i][j] = '*';  // Use '*' to create the heart
            }
        }
    }
}

// Function to display the pixel art
void displayPixelArt(char art[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

// Function to save pixel art to a file
void savePixelArt(char art[HEIGHT][WIDTH], const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                fprintf(file, "%c", art[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        printf("Pixel art saved to %s\n", filename);
    } else {
        printf("Error: Could not open file %s for writing.\n", filename);
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH];
    createPixelArt(pixelArt);
    
    printf("\nWelcome to the Pixel Art Generator!\n");
    printf("Here is your heart pixel art:\n\n");
    displayPixelArt(pixelArt);

    // Prompt for saving the art
    char filename[50];
    printf("Would you like to save the art? (yes/no): ");
    char response[10];
    scanf("%s", response);
    
    if (strcmp(response, "yes") == 0) {
        printf("Enter filename to save: ");
        scanf("%s", filename);
        savePixelArt(pixelArt, filename);
    } else {
        printf("No worries! Enjoy your pixel art creation.\n");
    }

    return 0;
}