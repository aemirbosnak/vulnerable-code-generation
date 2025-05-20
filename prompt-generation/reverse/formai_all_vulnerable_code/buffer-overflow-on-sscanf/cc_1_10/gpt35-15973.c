//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WIDTH 160
#define MAX_HEIGHT 120

// Create a struct to hold the image data
struct Image {
    int width;
    int height;
    int data[MAX_WIDTH][MAX_HEIGHT];
};

// Function to load an image from a file
bool loadImage(const char* filename, struct Image* image) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    
    // Read the width and height from the first line
    char line[256];
    fgets(line, sizeof(line), file);
    sscanf(line, "%d %d", &image->width, &image->height);
    
    // Loop over the rest of the file and read the image data
    for (int y = 0; y < image->height; y++) {
        fgets(line, sizeof(line), file);
        char* ptr = line;
        for (int x = 0; x < image->width; x++) {
            // Extract the value from the string and store it in the image struct
            image->data[x][y] = atoi(ptr);
            ptr = strchr(ptr, ' ');
            if (ptr == NULL) {
                break;
            }
            ptr++;
        }
    }
    
    // Close the file and return success
    fclose(file);
    return true;
}

// Function to save an image to a file
bool saveImage(const char* filename, const struct Image* image) {
    // Open the file
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return false;
    }
    
    // Write the width and height to the first line
    fprintf(file, "%d %d\n", image->width, image->height);
    
    // Loop over the image data and write it to the file
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(file, "%d ", image->data[x][y]);
        }
        fprintf(file, "\n");
    }
    
    // Close the file and return success
    fclose(file);
    return true;
}

// Function to invert the colors of an image
void invert(struct Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[x][y] = 255 - image->data[x][y];
        }
    }
}

// Function to flip an image horizontally
void flipHorizontal(struct Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int temp = image->data[x][y];
            image->data[x][y] = image->data[image->width - 1 - x][y];
            image->data[image->width - 1 - x][y] = temp;
        }
    }
}

// Function to flip an image vertically
void flipVertical(struct Image* image) {
    for (int x = 0; x < image->width; x++) {
        for (int y = 0; y < image->height / 2; y++) {
            int temp = image->data[x][y];
            image->data[x][y] = image->data[x][image->height - 1 - y];
            image->data[x][image->height - 1 - y] = temp;
        }
    }
}

int main(int argc, char* argv[]) {
    struct Image image;
    const char* filename = NULL;
    
    // Check if a filename was passed as a command-line argument
    if (argc > 1) {
        filename = argv[1];
    }
    
    // Load the image from a file
    if (filename != NULL) {
        if (!loadImage(filename, &image)) {
            fprintf(stderr, "Error: Failed to load image from file '%s'.\n", filename);
            return 1;
        }
    } else {
        // Create a default image
        image.width = MAX_WIDTH;
        image.height = MAX_HEIGHT;
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width; x++) {
                image.data[x][y] = (x + y) % 256;
            }
        }
    }
    
    // Apply a series of transformations to the image
    invert(&image);
    flipHorizontal(&image);
    flipVertical(&image);
    
    // Save the transformed image to a file
    const char* outputFilename = "output.pgm";
    if (!saveImage(outputFilename, &image)) {
        fprintf(stderr, "Error: Failed to save image to file '%s'.\n", outputFilename);
        return 1;
    }
    
    printf("Successfully processed image and saved result to '%s'.\n", outputFilename);
    
    return 0;
}