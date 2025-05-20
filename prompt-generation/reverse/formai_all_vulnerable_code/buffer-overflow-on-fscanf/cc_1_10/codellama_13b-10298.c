//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
// Simple Image Processing Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  int width;
  int height;
  int** pixels;
} Image;

// Flip the image horizontally
void flip_horizontal(Image* image) {
  int i, j;
  int tmp;

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width / 2; j++) {
      tmp = image->pixels[i][j];
      image->pixels[i][j] = image->pixels[i][image->width - j - 1];
      image->pixels[i][image->width - j - 1] = tmp;
    }
  }
}

// Change brightness/contrast of the image
void adjust_brightness(Image* image, int brightness, int contrast) {
  int i, j;
  int new_pixel;

  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      new_pixel = image->pixels[i][j] + brightness;
      new_pixel = (new_pixel * contrast) / 100;
      image->pixels[i][j] = new_pixel;
    }
  }
}

// Load image from file
Image* load_image(char* filename) {
  Image* image;
  FILE* file;
  int width, height;
  int i, j;

  // Open file and read width and height
  file = fopen(filename, "r");
  fscanf(file, "%d %d", &width, &height);

  // Allocate memory for image and pixels
  image = (Image*)malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = (int**)malloc(height * sizeof(int*));
  for (i = 0; i < height; i++) {
    image->pixels[i] = (int*)malloc(width * sizeof(int));
  }

  // Read pixels from file
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      fscanf(file, "%d", &image->pixels[i][j]);
    }
  }

  // Close file
  fclose(file);

  return image;
}

// Save image to file
void save_image(Image* image, char* filename) {
  FILE* file;
  int i, j;

  // Open file and write width and height
  file = fopen(filename, "w");
  fprintf(file, "%d %d\n", image->width, image->height);

  // Write pixels to file
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      fprintf(file, "%d ", image->pixels[i][j]);
    }
    fprintf(file, "\n");
  }

  // Close file
  fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
  Image* image;

  // Load image from file
  image = load_image("image.txt");

  // Flip image horizontally
  flip_horizontal(image);

  // Adjust brightness and contrast
  adjust_brightness(image, 10, 50);

  // Save image to file
  save_image(image, "output.txt");

  // Free memory
  free(image->pixels);
  free(image);

  return 0;
}