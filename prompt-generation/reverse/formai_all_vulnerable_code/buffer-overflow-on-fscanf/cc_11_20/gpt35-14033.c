//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define ASCII art characters
#define PIXEL ' '
#define UPPER_LEFT_CORNER '+'
#define HORIZONTAL_BORDER '-'
#define VERTICAL_BORDER '|'
#define NEWLINE '\n'
#define NULL_CHAR '\0'

int main() {
    // Open the image file and read the data
    FILE *image = fopen("image.ppm", "r");
    if (image == NULL) {
        printf("Error opening image file\n");
        return 1;
    }
    char buffer[128];
    fgets(buffer, sizeof(buffer), image);
    fgets(buffer, sizeof(buffer), image);
    int width, height;
    fscanf(image, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), image);
    int max_color_value;
    fscanf(image, "%d", &max_color_value);
    fgetc(image);

    // Calculate the character dimensions for the ASCII art
    int char_width = 2;  // Each character represents a 2x1 px region
    int char_height = 1;
    int art_width = width / char_width;
    int art_height = height / char_height;

    // Allocate memory for the ASCII art data
    char **ascii_art = malloc(sizeof(char*) * art_height);
    for (int i = 0; i < art_height; i++) {
        ascii_art[i] = malloc(sizeof(char) * (art_width + 1));
        memset(ascii_art[i], NULL_CHAR, sizeof(char) * (art_width + 1));
    }

    // Convert the image data to ASCII art
    for (int y = 0; y < art_height; y++) {
        for (int x = 0; x < art_width; x++) {
            // Calculate the pixel values for the 2x1 region
            int r = 0, g = 0, b = 0;
            for (int i = 0; i < char_height; i++) {
                for (int j = 0; j < char_width; j++) {
                    int px_x = x * char_width + j;
                    int px_y = y * char_height + i;
                    fseek(image, 3 * (px_y * width + px_x), SEEK_SET);
                    r += fgetc(image);
                    g += fgetc(image);
                    b += fgetc(image);
                }
            }
            r /= 4;
            g /= 4;
            b /= 4;

            // Convert the pixel values to a character
            if (r + g + b > 3 * max_color_value / 2) {
                ascii_art[y][x] = PIXEL;
            } else {
                ascii_art[y][x] = UPPER_LEFT_CORNER;
            }
        }
    }

    // Print the ASCII art
    for (int y = 0; y < art_height; y++) {
        // Print the top border of the character cell
        for (int i = 0; i < char_width; i++) {
            printf("%c", HORIZONTAL_BORDER);
        }
        printf("%c", UPPER_LEFT_CORNER);
        for (int x = 0; x < art_width; x++) {
            printf("%c", HORIZONTAL_BORDER);
        }
        printf("%c\n", UPPER_LEFT_CORNER);

        // Print the character row
        for (int i = 0; i < char_height; i++) {
            printf("%c", VERTICAL_BORDER);
            for (int x = 0; x < art_width; x++) {
                printf("%c%c", ascii_art[y][x], ascii_art[y][x]);
            }
            printf("%c\n", VERTICAL_BORDER);
        }
    }

    // Print the bottom border of the last character cell
    for (int i = 0; i < char_width; i++) {
        printf("%c", HORIZONTAL_BORDER);
    }
    printf("%c", UPPER_LEFT_CORNER);
    for (int x = 0; x < art_width; x++) {
        printf("%c", HORIZONTAL_BORDER);
    }
    printf("%c\n", UPPER_LEFT_CORNER);

    // Clean up memory and close file
    for (int i = 0; i < art_height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
    fclose(image);

    return 0;
}