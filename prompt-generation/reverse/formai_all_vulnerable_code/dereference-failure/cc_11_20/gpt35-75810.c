//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
// This program takes a C image file and converts it into ASCII art
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200 // Maximum length of a line in the image file
#define MAX_IMAGE_WIDTH 100 // Maximum width of the C image
#define MAX_IMAGE_HEIGHT 100 // Maximum height of the C image

char map[] = "@%#*+=-:. "; // ASCII character set to represent different intensities of grey

int main(int argc, char *argv[]) {

    // Check if filename is provided as command line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open image file
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Cannot open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read image dimensions from first line of file
    int width, height;
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp);
    sscanf(line, "%d %d", &width, &height);

    // Check if image dimensions are within limits
    if (width > MAX_IMAGE_WIDTH || height > MAX_IMAGE_HEIGHT) {
        fprintf(stderr, "Error: Image dimensions exceed maximum limits.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for image matrix based on image dimensions
    int **image = (int **) calloc(height, sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *) calloc(width, sizeof(int));
    }

    // Read image data from file and store it in matrix
    for (int i = 0; i < height; i++) {
        fgets(line, MAX_LINE_LENGTH, fp);
        char *token = strtok(line, " ");
        for (int j = 0; j < width; j++) {
            image[i][j] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    // Close image file
    fclose(fp);

    // Generate ASCII art from image matrix
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = image[i][j] / 25; // Map intensities to ASCII characters
            printf("%c", map[intensity]);
        }
        printf("\n");
    }

    // Free memory allocated for image matrix
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}