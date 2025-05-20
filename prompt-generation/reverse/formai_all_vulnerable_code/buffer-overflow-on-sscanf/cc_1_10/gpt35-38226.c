//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define MAX_PIXEL 255

// Function to convert image to ASCII art
void imageToAscii(char filename[]) {
    FILE *fr = fopen(filename, "rb");
    if (fr == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Get image dimensions
    char buf[1024];
    fgets(buf, 1024, fr); // P6
    fgets(buf, 1024, fr); // Width and Height
    int width, height;
    sscanf(buf, "%d %d", &width, &height);
    fgets(buf, 1024, fr); // Maximum pixel value

    // Check if image is too large
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions too large.\n");
        fclose(fr);
        return;
    }

    // Allocate memory for pixel array
    unsigned char *pixelData = (unsigned char *) malloc(width * height * 3);
    if (pixelData == NULL) {
        printf("Error: Could not allocate memory for pixel data.\n");
        fclose(fr);
        return;
    }

    // Read pixel data from file
    int size = fread(pixelData, 1, width * height * 3, fr);
    if (size != width * height * 3) {
        printf("Error: Could not read pixel data from file.\n");
        fclose(fr);
        free(pixelData);
        return;
    }
    fclose(fr);

    // Convert pixel data to ASCII art
    char asciiData[MAX_HEIGHT][MAX_WIDTH + 1];
    memset(asciiData, ' ', MAX_HEIGHT * (MAX_WIDTH + 1)); // Initialize to spaces
    int index = 0;
    for (int i = 0; i < height; i += (int) round((double) height / MAX_HEIGHT)) {
        for (int j = 0; j < width * 3; j += 3 * (int) round((double) width / MAX_WIDTH)) {
            int r = pixelData[i * width * 3 + j];
            int g = pixelData[i * width * 3 + j + 1];
            int b = pixelData[i * width * 3 + j + 2];
            int grayValue = (int) round(0.2989 * r + 0.5870 * g + 0.1140 * b);
            int asciiIndex = (int) round((double) grayValue / MAX_PIXEL * 9);
            if (asciiIndex > 9) {
                asciiIndex = 9;
            }
            asciiData[index / MAX_WIDTH][index % MAX_WIDTH] = " .:-=+*#%@@"[asciiIndex];
            index++;
        }
        index += MAX_WIDTH - (index % MAX_WIDTH);
    }
    free(pixelData);

    // Print ASCII art to console
    for (int i = 0; i < MAX_HEIGHT; i++) {
        asciiData[i][MAX_WIDTH] = '\n';
        asciiData[i][MAX_WIDTH + 1] = '\0';
        printf("%s", asciiData[i]);
    }
}

// Main function to test imageToAscii function
int main() {
    char filename[] = "test.ppm";
    imageToAscii(filename);
    return 0;
}