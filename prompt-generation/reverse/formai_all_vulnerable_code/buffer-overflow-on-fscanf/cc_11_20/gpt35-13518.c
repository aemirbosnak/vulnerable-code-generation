//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to hold color values
typedef struct {
    int red;
    int green;
    int blue;
} Color;

// Function to read a PPM image file
Color** readPPM(char* filename, int *width, int *height) {
    Color **image;
    FILE *file;
    char magicNum[3];
    int maxVal;
    int x, y;

    // Open the file in read binary mode
    file = fopen(filename, "rb");

    // Verify that the file was successfully opened
    if (file == NULL) {
        printf("Error: Failed to open file\n");
        exit(1);
    }

    // Read in the PPM magic number, width, height, and maximum value
    fscanf(file, "%s\n%d %d\n%d\n", magicNum, width, height, &maxVal);

    // Verify that the image is in PPM format
    if (strcmp(magicNum, "P3") != 0) {
        printf("Error: File format not supported\n");
        exit(1);
    }

    // Allocate memory for the image array
    image = (Color**) malloc((*height) * sizeof(Color*));
    for (y = 0; y < (*height); y++) {
        image[y] = (Color*) malloc((*width) * sizeof(Color));
    }

    // Read in the color values for each pixel
    for (y = 0; y < (*height); y++) {
        for (x = 0; x < (*width); x++) {
            fscanf(file, "%d %d %d", &image[y][x].red, &image[y][x].green, &image[y][x].blue);
        }
    }

    // Close the file
    fclose(file);

    // Return a pointer to the image array
    return image;
}

// Function to write a PPM image file
void writePPM(char* filename, Color** image, int width, int height) {
    FILE *file;
    int x, y;

    // Open the file in write binary mode
    file = fopen(filename, "wb");

    // Verify that the file was successfully opened
    if (file == NULL) {
        printf("Error: Failed to open file\n");
        exit(1);
    }

    // Write out the PPM header information
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    // Write out the color values for each pixel
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fprintf(file, "%d %d %d ", image[y][x].red, image[y][x].green, image[y][x].blue);
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);
}

int main(int argc, char* argv[]) {
    Color** image;
    int width, height;
    int x, y;

    // Verify that the user provided enough arguments
    if (argc < 3) {
        printf("Error: Not enough arguments\n");
        exit(1);
    }

    // Read in the image file
    image = readPPM(argv[1], &width, &height);

    // Apply image manipulation based on user input
    if (strcmp(argv[2], "grayscale") == 0) {
        // Convert the image to grayscale
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int grayscale = (image[y][x].red + image[y][x].green + image[y][x].blue) / 3;
                image[y][x].red = grayscale;
                image[y][x].green = grayscale;
                image[y][x].blue = grayscale;
            }
        }
    }
    else if (strcmp(argv[2], "invert") == 0) {
        // Invert the image colors
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                image[y][x].red = 255 - image[y][x].red;
                image[y][x].green = 255 - image[y][x].green;
                image[y][x].blue = 255 - image[y][x].blue;
            }
        }
    }
    else if (strcmp(argv[2], "rotate") == 0) {
        // Rotate the image 90 degrees clockwise
        Color **newImage;
        newImage = (Color**) malloc(width * sizeof(Color*));
        for (x = 0; x < width; x++) {
            newImage[x] = (Color*) malloc(height * sizeof(Color));
        }
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                newImage[x][height-y-1] = image[y][x];
            }
        }
        image = newImage;
        int temp = width;
        width = height;
        height = temp;
    }
    else if (strcmp(argv[2], "brightness") == 0) {
        // Adjust the brightness of the image
        int brightness;
        if (argc < 4 || sscanf(argv[3], "%d", &brightness) != 1) {
            printf("Error: Invalid brightness argument\n");
            exit(1);
        }
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                image[y][x].red += brightness;
                if (image[y][x].red < 0) {
                    image[y][x].red = 0;
                }
                else if (image[y][x].red > 255) {
                    image[y][x].red = 255;
                }
                image[y][x].green += brightness;
                if (image[y][x].green < 0) {
                    image[y][x].green = 0;
                }
                else if (image[y][x].green > 255) {
                    image[y][x].green = 255;
                }
                image[y][x].blue += brightness;
                if (image[y][x].blue < 0) {
                    image[y][x].blue = 0;
                }
                else if (image[y][x].blue > 255) {
                    image[y][x].blue = 255;
                }
            }
        }
    }
    else if (strcmp(argv[2], "threshold") == 0) {
        // Convert the image to black and white based on a given threshold
        int threshold;
        if (argc < 4 || sscanf(argv[3], "%d", &threshold) != 1) {
            printf("Error: Invalid threshold argument\n");
            exit(1);
        }
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int grayscale = (image[y][x].red + image[y][x].green + image[y][x].blue) / 3;
                if (grayscale < threshold) {
                    image[y][x].red = 0;
                    image[y][x].green = 0;
                    image[y][x].blue = 0;
                }
                else {
                    image[y][x].red = 255;
                    image[y][x].green = 255;
                    image[y][x].blue = 255;
                }
            }
        }
    }
    else {
        // Invalid action
        printf("Error: Invalid action\n");
        exit(1);
    }

    // Write out the modified image
    writePPM(argv[1], image, width, height);

    // Free the memory used by the image array
    for (y = 0; y < height; y++) {
        free(image[y]);
    }
    free(image);

    // Exit the program with no errors
    return 0;
}