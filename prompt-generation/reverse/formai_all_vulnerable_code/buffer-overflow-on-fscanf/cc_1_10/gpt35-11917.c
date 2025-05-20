//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 50

// A structure to hold an image
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function to load an image from a file
Image* loadImage(char* filename) {
    FILE* fp;
    Image* img = NULL;
    char type[3];
    int width, height, maxval, i, j;
    unsigned char* data;

    // Open the image file
    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Unable to open file %s\n", filename);
        goto load_error;
    }

    // Read the image type
    if (fscanf(fp, "%2s\n", type) != 1) {
        printf("Error: Unable to read image type\n");
        goto load_error;
    }
    if (strcmp(type, "P5") != 0) {
        printf("Error: Unsupported image type: %s\n", type);
        goto load_error;
    }

    // Read the image dimensions
    if ((fscanf(fp, "%d %d\n", &width, &height) != 2) || (width <= 0) || (height <= 0)) {
        printf("Error: Invalid image dimensions\n");
        goto load_error;
    }

    // Read the maximum pixel value
    if ((fscanf(fp, "%d\n", &maxval) != 1) || (maxval > 255)) {
        printf("Error: Invalid maximum pixel value\n");
        goto load_error;
    }

    // Allocate memory for the image data
    data = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    if (!data) {
        printf("Error: Unable to allocate memory for image data\n");
        goto load_error;
    }

    // Read the image data
    if (fread(data, sizeof(unsigned char), width * height, fp) != width * height) {
        printf("Error: Unable to read image data\n");
        free(data);
        goto load_error;
    }

    // Close the image file
    fclose(fp);

    // Allocate memory for the image structure
    img = (Image*)malloc(sizeof(Image));
    if (!img) {
        printf("Error: Unable to allocate memory for image structure\n");
        free(data);
        goto load_error;
    }

    // Save the image data and dimensions
    img->data = data;
    img->width = width;
    img->height = height;

    return img;

load_error:
    if (fp) fclose(fp);
    if (img) free(img);
    return NULL;
}

// Function to save an image to a file
bool saveImage(Image* img, char* filename) {
    FILE* fp;

    // Open the output file
    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Unable to open output file %s\n", filename);
        return false;
    }

    // Write the output file header
    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, 255);

    // Write the output file data
    if (fwrite(img->data, sizeof(unsigned char), img->width * img->height, fp) != img->width * img->height) {
        printf("Error: Unable to write output file %s\n", filename);
        fclose(fp);
        return false;
    }

    // Close the output file
    fclose(fp);

    return true;
}

// Function to flip an image horizontally
void flipHorizontal(Image* img) {
    unsigned char temp;
    int i, j;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            // Swap the pixels
            temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + img->width - j - 1];
            img->data[i * img->width + img->width - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(Image* img, int level) {
    int i;

    for (i = 0; i < img->width * img->height; i++) {
        if (img->data[i] + level > 255) {
            img->data[i] = 255;
        } else if (img->data[i] + level < 0) {
            img->data[i] = 0;
        } else {
            img->data[i] += level;
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(Image* img, double factor) {
    int i;
    double value;

    for (i = 0; i < img->width * img->height; i++) {
        value = img->data[i] * factor;
        if (value > 255) {
            img->data[i] = 255;
        } else if (value < 0) {
            img->data[i] = 0;
        } else {
            img->data[i] = (unsigned char)value;
        }
    }
}

int main(int argc, char* argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    Image* img = NULL;

    // Get the filename from the user
    printf("Enter the filename of the image: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Load the image
    img = loadImage(filename);
    if (!img) {
        printf("Error: Unable to load image from %s\n", filename);
        return 1;
    }

    // Flip the image horizontally
    printf("Flipping image horizontally...\n");
    flipHorizontal(img);

    // Adjust the brightness of the image
    printf("Adjusting brightness...\n");
    adjustBrightness(img, 50);

    // Adjust the contrast of the image
    printf("Adjusting contrast...\n");
    adjustContrast(img, 1.5);

    // Save the modified image
    printf("Saving modified image...\n");
    if (!saveImage(img, "output.pgm")) {
        printf("Error: Unable to save modified image\n");
        return 1;
    }

    // Free the image data
    free(img->data);
    free(img);

    printf("Image processing complete!\n");
    return 0;
}