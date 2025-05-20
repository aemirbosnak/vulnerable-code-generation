//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
// Behold, the C Image Wrangling Bonanza!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pixel struct, for the RGB magic
typedef struct {
  unsigned char r, g, b;
} Pixel;

// Image struct, storing the width, height, and glorious pixels
typedef struct {
  int width, height;
  Pixel *data;
} Image;

// Image loading extravaganza
Image *loadImage(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    printf("Image load failed, your path is a dud!\n");
    return NULL;
  }

  // Read header info
  char header[100];
  fscanf(file, "%s", header);
  if (strcmp(header, "P6") != 0) {
    printf("Unsupported image format, we only dig P6!\n");
    fclose(file);
    return NULL;
  }
  int width, height, maxval;
  fscanf(file, "%d %d\n%d\n", &width, &height, &maxval);

  // Allocate space for our image
  Image *image = (Image *)malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->data = (Pixel *)malloc(width * height * sizeof(Pixel));

  // Read pixel data
  fread(image->data, sizeof(Pixel), width * height, file);
  fclose(file);
  printf("Image loaded with %d pixels, brace yourself!\n", width * height);
  return image;
}

// Image saving brilliance
void saveImage(Image *image, const char *filename) {
  FILE *file = fopen(filename, "wb");
  fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
  fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
  fclose(file);
  printf("Image saved, ready for the world to see!\n");
}

// Pixel flipping magic
void flipImage(Image *image) {
  for (int i = 0; i < image->height / 2; i++) {
    for (int j = 0; j < image->width; j++) {
      Pixel temp = image->data[i * image->width + j];
      image->data[i * image->width + j] = image->data[(image->height - 1 - i) * image->width + j];
      image->data[(image->height - 1 - i) * image->width + j] = temp;
    }
  }
  printf("Image flipped, standing tall like a proud warrior!\n");
}

// Brightness/contrast adjustment wizardry
void adjustBrightnessContrast(Image *image, int brightness, int contrast) {
  // Apply brightness adjustment
  for (int i = 0; i < image->width * image->height; i++) {
    image->data[i].r += brightness;
    image->data[i].g += brightness;
    image->data[i].b += brightness;
  }

  // Apply contrast adjustment
  double factor = (259.0 * (contrast + 255)) / (255.0 * (259 - contrast));
  for (int i = 0; i < image->width * image->height; i++) {
    image->data[i].r = (image->data[i].r - 128) * factor + 128;
    image->data[i].g = (image->data[i].g - 128) * factor + 128;
    image->data[i].b = (image->data[i].b - 128) * factor + 128;
  }

  printf("Brightness and contrast adjusted, prepare your eyes for the transformation!\n");
}

// Grand finale, the program entry point
int main(int argc, char **argv) {
  if (argc < 3 || argc > 5) {
    printf("Usage: %s <input-image> <output-image> [brightness] [contrast]\n", argv[0]);
    return 1;
  }

  // Load the image, let the colors flow!
  Image *image = loadImage(argv[1]);
  if (!image) {
    return 1;
  }

  // Handle arguments, flip if needed
  if (argc >= 4) {
    flipImage(image);
  }

  // Adjust brightness and contrast, make those pixels pop!
  if (argc >= 5) {
    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);
    adjustBrightnessContrast(image, brightness, contrast);
  }

  // Save the masterpiece, let the world witness its beauty
  saveImage(image, argv[2]);

  // Free the image, release the pixels!
  free(image->data);
  free(image);
  return 0;
}