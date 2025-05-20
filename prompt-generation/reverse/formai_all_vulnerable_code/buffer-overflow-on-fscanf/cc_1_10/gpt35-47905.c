//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_FILE_LENGTH 1000
#define MAX_IMAGE_SIZE 500

// Define Data Structures
struct Image {
  // Image Metadata
  char filename[MAX_FILE_LENGTH];
  int width;
  int height;

  // Image Data
  int data[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
};

// Function to Load an Image from File
int loadImage(char *filename, struct Image *img) {
  // Open the File
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file '%s'\n", filename);
    return 0;
  }

  // Read Image Metadata
  fscanf(file, "%d %d", &img->width, &img->height);

  // Read Image Data
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      fscanf(file, "%d", &img->data[i][j]);
    }
  }

  // Close the File and Return Success
  fclose(file);
  return 1;
}

// Function to Save an Image to File
int saveImage(char *filename, struct Image *img) {
  // Create the File
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error: Could not create file '%s'\n", filename);
    return 0;
  }

  // Write Image Metadata
  fprintf(file, "%d %d\n", img->width, img->height);

  // Write Image Data
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      fprintf(file, "%d ", img->data[i][j]);
    }
    fprintf(file, "\n");
  }

  // Close the File and Return Success
  fclose(file);
  return 1;
}

// Function to Invert an Image
void invertImage(struct Image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      img->data[i][j] = 255 - img->data[i][j];
    }
  }
}

// Function to Convert an Image to Grayscale
void grayscaleImage(struct Image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      int gray = (img->data[i][j] >> 2) + (img->data[i][j] >> 4) + (img->data[i][j] >> 5);
      img->data[i][j] = gray;
    }
  }
}

// Function to Blur an Image
void blurImage(struct Image *img) {
  int kernel[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
  int kernelSum = 16;

  // Copy the Image Data
  int copy[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
  memcpy(copy, img->data, sizeof(copy));

  // Apply the Kernel
  for (int i = 1; i < img->height - 1; i++) {
    for (int j = 1; j < img->width - 1; j++) {
      int sum = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          sum += kernel[k + 1][l + 1] * copy[i + k][j + l];
        }
      }
      img->data[i][j] = sum / kernelSum;
    }
  }
}

// Main Function
int main() {
  // Load an Image
  char filename[MAX_FILE_LENGTH] = "input.txt";
  struct Image img;
  if (!loadImage(filename, &img)) {
    return 1;
  }

  // Invert the Image
  invertImage(&img);
  saveImage("output_invert.txt", &img);

  // Convert the Image to Grayscale
  grayscaleImage(&img);
  saveImage("output_grayscale.txt", &img);

  // Blur the Image
  blurImage(&img);
  saveImage("output_blur.txt", &img);

  // Return Success
  return 0;
}