//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
// D E K: Image Processing in C

#include <stdio.h>
#include <stdlib.h>

// Image data structure
typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  // Read the image header
  int width, height;
  if (fscanf(fp, "P5 %d %d\n", &width, &height) != 2) {
    fclose(fp);
    return NULL;
  }

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * sizeof(unsigned char));
  if (data == NULL) {
    fclose(fp);
    return NULL;
  }

  // Read the image data
  if (fread(data, sizeof(unsigned char), width * height, fp) != width * height) {
    fclose(fp);
    free(data);
    return NULL;
  }

  fclose(fp);

  // Create a new image struct
  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    free(data);
    return NULL;
  }

  image->width = width;
  image->height = height;
  image->data = data;

  return image;
}

// Save an image to a file
int save_image(const Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    return -1;
  }

  // Write the image header
  fprintf(fp, "P5 %d %d\n", image->width, image->height);

  // Write the image data
  fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

  fclose(fp);

  return 0;
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width / 2; x++) {
      unsigned char temp = image->data[y * image->width + x];
      image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
      image->data[y * image->width + image->width - x - 1] = temp;
    }
  }
}

// Flip an image vertically
void flip_vertical(Image *image) {
  for (int y = 0; y < image->height / 2; y++) {
    for (int x = 0; x < image->width; x++) {
      unsigned char temp = image->data[y * image->width + x];
      image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
      image->data[(image->height - y - 1) * image->width + x] = temp;
    }
  }
}

// Adjust the brightness of an image
void adjust_brightness(Image *image, int brightness) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int new_brightness = image->data[y * image->width + x] + brightness;
      if (new_brightness < 0) {
        new_brightness = 0;
      } else if (new_brightness > 255) {
        new_brightness = 255;
      }
      image->data[y * image->width + x] = new_brightness;
    }
  }
}

// Adjust the contrast of an image
void adjust_contrast(Image *image, int contrast) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int new_contrast = (image->data[y * image->width + x] - 128) * contrast + 128;
      if (new_contrast < 0) {
        new_contrast = 0;
      } else if (new_contrast > 255) {
        new_contrast = 255;
      }
      image->data[y * image->width + x] = new_contrast;
    }
  }
}

// Free the memory allocated for an image
void free_image(Image *image) {
  if (image != NULL) {
    free(image->data);
    free(image);
  }
}

// Main function
int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <input_image> <output_image> <operation> <value>\n", argv[0]);
    fprintf(stderr, "Operations:\n");
    fprintf(stderr, "  -h: Flip the image horizontally\n");
    fprintf(stderr, "  -v: Flip the image vertically\n");
    fprintf(stderr, "  -b: Adjust the brightness of the image\n");
    fprintf(stderr, "  -c: Adjust the contrast of the image\n");
    return 1;
  }

  // Load the input image
  Image *image = load_image(argv[1]);
  if (image == NULL) {
    fprintf(stderr, "Error: could not load input image '%s'\n", argv[1]);
    return 1;
  }

  // Perform the specified operation
  if (strcmp(argv[3], "-h") == 0) {
    flip_horizontal(image);
  } else if (strcmp(argv[3], "-v") == 0) {
    flip_vertical(image);
  } else if (strcmp(argv[3], "-b") == 0) {
    adjust_brightness(image, atoi(argv[4]));
  } else if (strcmp(argv[3], "-c") == 0) {
    adjust_contrast(image, atoi(argv[4]));
  } else {
    fprintf(stderr, "Error: unknown operation '%s'\n", argv[3]);
    free_image(image);
    return 1;
  }

  // Save the output image
  if (save_image(image, argv[2]) != 0) {
    fprintf(stderr, "Error: could not save output image '%s'\n", argv[2]);
    free_image(image);
    return 1;
  }

  // Free the memory allocated for the image
  free_image(image);

  return 0;
}