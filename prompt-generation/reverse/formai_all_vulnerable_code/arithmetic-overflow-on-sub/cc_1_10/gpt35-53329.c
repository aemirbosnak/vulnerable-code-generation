//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum dimensions
#define MAX_WIDTH 500
#define MAX_HEIGHT 500

// Define functions
void load_image(char filename[]);
void save_image(char filename[]);
void invert_image();
void flip_image();
void grayscale_image();
void blur_image();

// Define image data structure
struct Image {
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT];
};

// Declare global variables
struct Image original_image;
struct Image edited_image;

int main() {

    // Initialize edited_image to all zeroes
    memset(&edited_image, 0, sizeof(edited_image));

    // Prompt user for filename
    printf("Enter filename: ");
    char filename[50];
    scanf("%s", filename);

    // Load image from file
    load_image(filename);

    // Apply transformation
    flip_image();

    // Save image to file
    save_image("edited_image.txt");

    return 0;
}

void load_image(char filename[]) {
    FILE *fp;
    int ch;
    int row = 0;
    int col = 0;

    // Open file
    fp = fopen(filename, "r");

    // Read dimensions from file
    fscanf(fp, "%d %d", &original_image.width, &original_image.height);

    // Read pixels from file
    while((ch = fgetc(fp)) != EOF) {
        if(ch == '\n') {
            row++;
            col = 0;
        } else {
            original_image.pixels[col][row] = ch - '0';
            col++;
        }
    }

    // Close file
    fclose(fp);
}

void save_image(char filename[]) {
    FILE *fp;
    int row, col;

    // Open file
    fp = fopen(filename, "w");

    // Write dimensions to file
    fprintf(fp, "%d %d\n", edited_image.width, edited_image.height);

    // Write pixels to file
    for(row = 0; row < edited_image.height; row++) {
        for(col = 0; col < edited_image.width; col++) {
            fprintf(fp, "%d", edited_image.pixels[col][row]);
        }
        fprintf(fp, "\n");
    }

    // Close file
    fclose(fp);
}

void invert_image() {
    int row, col;

    // Copy image dimensions
    edited_image.width = original_image.width;
    edited_image.height = original_image.height;

    // Invert pixels
    for(row = 0; row < original_image.height; row++) {
        for(col = 0; col < original_image.width; col++) {
            edited_image.pixels[col][row] = !original_image.pixels[col][row];
        }
    }
}

void flip_image() {
    int row, col;

    // Copy image dimensions
    edited_image.width = original_image.width;
    edited_image.height = original_image.height;

    // Flip pixels horizontally
    for(row = 0; row < original_image.height; row++) {
        for(col = 0; col < original_image.width; col++) {
            edited_image.pixels[original_image.width - col - 1][row] = original_image.pixels[col][row];
        }
    }
}

void grayscale_image() {
    int row, col, sum;

    // Copy image dimensions
    edited_image.width = original_image.width;
    edited_image.height = original_image.height;

    // Convert pixels to grayscale
    for(row = 0; row < original_image.height; row++) {
        for(col = 0; col < original_image.width; col++) {
            sum = original_image.pixels[col][row];
            edited_image.pixels[col][row] = sum / 3;
        }
    }
}

void blur_image() {
    int row, col, sum;

    // Copy image dimensions
    edited_image.width = original_image.width;
    edited_image.height = original_image.height;

    // Blur pixels
    for(row = 0; row < original_image.height; row++) {
        for(col = 0; col < original_image.width; col++) {
            if(row == 0 || row == original_image.height - 1 || col == 0 || col == original_image.width - 1) {
                edited_image.pixels[col][row] = original_image.pixels[col][row];
            } else {
                sum = original_image.pixels[col - 1][row - 1] + original_image.pixels[col - 1][row] + original_image.pixels[col - 1][row + 1] +
                original_image.pixels[col][row - 1] + original_image.pixels[col][row] + original_image.pixels[col][row + 1] +
                original_image.pixels[col + 1][row - 1] + original_image.pixels[col + 1][row] + original_image.pixels[col + 1][row + 1];
                edited_image.pixels[col][row] = sum / 9;
            }
        }
    }
}