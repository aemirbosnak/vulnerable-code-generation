//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Creates a two-dimensional array to store the ASCII art
char ascii[MAX_HEIGHT][MAX_WIDTH];

// Create a structure to store the RGB values of a pixel
struct pixel {
    unsigned char r, g, b;
};

int main() {
    char input_file[100];
    FILE *fp;
    int width, height, i, j;
    struct pixel image[MAX_HEIGHT][MAX_WIDTH];

    printf("Enter the filename of the image: ");
    scanf("%s", input_file);

    fp = fopen(input_file, "rb");
    if (!fp) {
        printf("Error: could not open file\n");
        return 1;
    }

    // Read the width and height of the image
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(width), 1, fp);
    fread(&height, sizeof(height), 1, fp);

    // Make sure the dimensions are within the limits of the ASCII art array
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image too large\n");
        return 1;
    }

    // Read the RGB values of each pixel and store them in the image array
    fseek(fp, 54, SEEK_SET);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&image[i][j], sizeof(struct pixel), 1, fp);
        }
    }

    // Convert each pixel to its corresponding ASCII character
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int intensity = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            if (intensity < 64) {
                ascii[i][j] = '@';
            } else if (intensity < 128) {
                ascii[i][j] = '#';
            } else if (intensity < 192) {
                ascii[i][j] = '$';
            } else if (intensity < 256) {
                ascii[i][j] = '*';
            }
        }
    }

    // Print the ASCII art to the console
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}