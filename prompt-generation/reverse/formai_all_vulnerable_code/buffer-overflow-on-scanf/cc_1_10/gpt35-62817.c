//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store the compressed image data
typedef struct {
    int width;
    int height;
    int num_colors;
    int* colors; // Store the frequency of each color
    int** pixels; // Store the pixel values as indices into the colors array
} CompressedImage;

// Helper function to find the index of a color in the colors array
int find_color_index(int color, int* colors, int num_colors) {
    for (int i = 0; i < num_colors; i++) {
        if (colors[i] == color) {
            return i;
        }
    }
    return -1; // Error, color not found in array
}

int main() {
    // First read in the original uncompressed image
    int width, height, max_value;
    scanf("%d %d %d", &width, &height, &max_value);
    
    // Allocate memory to store the pixel data
    int** pixels = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(int));
    }
    
    // Read in the pixel data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &pixels[i][j]);
        }
    }
    
    // Determine the number of unique colors in the image
    int* colors = malloc(max_value * sizeof(int));
    int num_colors = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int color = pixels[i][j];
            if (find_color_index(color, colors, num_colors) == -1) {
                colors[num_colors++] = color;
            }
        }
    }
    
    // Compress the image by storing each pixel as an index into the colors array
    CompressedImage compressed;
    compressed.width = width;
    compressed.height = height;
    compressed.num_colors = num_colors;
    compressed.colors = colors;
    compressed.pixels = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        compressed.pixels[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            compressed.pixels[i][j] = find_color_index(pixels[i][j], colors, num_colors);
        }
    }
    
    // Print out the compressed image data
    printf("%d %d %d\n", compressed.width, compressed.height, compressed.num_colors);
    for (int i = 0; i < compressed.num_colors; i++) {
        printf("%d ", compressed.colors[i]);
    }
    printf("\n");
    for (int i = 0; i < compressed.height; i++) {
        for (int j = 0; j < compressed.width; j++) {
            printf("%d ", compressed.pixels[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory used by the pixel data and compressed image data
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
    for (int i = 0; i < compressed.height; i++) {
        free(compressed.pixels[i]);
    }
    free(compressed.pixels);
    free(colors);
    
    return 0;
}