//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Behold, the legendary steganographer!
typedef struct {
  unsigned char *data;
  int size;
  int capacity;
} Image;

// Meet the pixel pusher, our very own Picasso!
typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

// Our trusty pixel peeker, always on the lookout!
Pixel get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->size || y < 0 || y >= image->size) {
    fprintf(stderr, "Oops, pixel coordinates out of bounds!\n");
    exit(1);
  }
  return (Pixel){image->data[y * image->size + x * 3], image->data[y * image->size + x * 3 + 1], image->data[y * image->size + x * 3 + 2]};
}

// A nimble ninja, setting pixels with ease!
void set_pixel(Image *image, int x, int y, Pixel pixel) {
  if (x < 0 || x >= image->size || y < 0 || y >= image->size) {
    fprintf(stderr, "Oops, pixel coordinates out of bounds!\n");
    exit(1);
  }
  image->data[y * image->size + x * 3] = pixel.red;
  image->data[y * image->size + x * 3 + 1] = pixel.green;
  image->data[y * image->size + x * 3 + 2] = pixel.blue;
}

// Our master spy, extracting secrets from images!
unsigned char get_bit(unsigned char byte, int bit_index) {
  return (byte >> bit_index) & 1;
}

// An expert tailor, hiding bits in pixels!
unsigned char set_bit(unsigned char byte, int bit_index, unsigned char bit) {
  if (bit) {
    byte |= (1 << bit_index);
  } else {
    byte &= ~(1 << bit_index);
  }
  return byte;
}

// A fearless adventurer, diving into images!
Image *load_image(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Error: Couldn't open image file!\n");
    exit(1);
  }

  // Sniffing out the image's dimensions and size
  fseek(file, 18, SEEK_SET);
  int width, height;
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);
  int size = width * height;

  // Allocating memory, building our image sanctuary
  Image *image = malloc(sizeof(Image));
  image->data = malloc(size * 3);
  image->size = size;
  image->capacity = size * 3;

  // Siphoning the image's pixels, one by one
  fseek(file, 54, SEEK_SET);
  fread(image->data, 1, size * 3, file);

  fclose(file);

  return image;
}

// A meticulous surgeon, saving images with precision!
void save_image(const char *filename, Image *image) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    fprintf(stderr, "Error: Couldn't save image file!\n");
    exit(1);
  }

  // Crafting the image header, like a culinary masterpiece
  unsigned char header[54] = {
    0x42, 0x4D, // Magic number
    (unsigned char)(image->size * 3 + 54), 0, 0, 0, // File size
    0, 0, // Reserved
    54, 0, 0, 0, // Offset to image data
    40, 0, 0, 0, // Header size
    (unsigned char)image->size, 0, 0, 0, // Image width
    (unsigned char)(image->size >> 8), 0, 0, 0, // Image height
    1, 0, // Number of color planes
    24, 0, // Bits per pixel
    0, 0, 0, 0, // Compression
    0, 0, 0, 0, // Image size
    0, 0, 0, 0, // Horizontal resolution
    0, 0, 0, 0, // Vertical resolution
    0, 0, 0, 0, // Number of colors
    0, 0, 0, 0, // Important colors
  };

  // Writing the header, the foundation of our image
  fwrite(header, 1, 54, file);

  // Pouring the pixels into the file, completing our work of art
  fwrite(image->data, 1, image->size * 3, file);

  fclose(file);
}

// The grand finale, where secrets dance in pixels!
int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s input_image.bmp output_image.bmp secret_message\n", argv[0]);
    return 1;
  }

  // Behold, the input image, our canvas for secrets!
  Image *input_image = load_image(argv[1]);

  // Welcome our output image, where secrets will reside!
  Image *output_image = malloc(sizeof(Image));
  *output_image = *input_image;

  // Unraveling the secret message, bit by bit!
  const char *secret_message = argv[3];
  int message_length = strlen(secret_message);

  // Declaring the current pixel, our trusty steed!
  Pixel pixel;

  // Stealthily weaving the secret into the pixels!
  int bit_index = 0;
  int byte_index = 0;
  int pixel_index = 0;
  while (byte_index < message_length) {
    // Selecting our pixel, the perfect hiding spot!
    pixel = get_pixel(output_image, pixel_index % input_image->size, pixel_index / input_image->size);

    // Sneaking the secret into the pixel, one bit at a time!
    unsigned char bit = get_bit(secret_message[byte_index], bit_index);
    pixel.red = set_bit(pixel.red, 7 - bit_index, bit);

    // Advancing our secret quest!
    bit_index++;
    if (bit_index == 8) {
      bit_index = 0;
      byte_index++;
    }

    // Moving on to the next pixel, our next hiding spot!
    pixel_index++;

    // Setting the pixel, sealing the secret within!
    set_pixel(output_image, pixel_index % input_image->size, pixel_index / input_image->size, pixel);
  }

  // Saving the output image, our secret-laden masterpiece!
  save_image(argv[2], output_image);

  // Mission accomplished, secrets safely hidden in plain sight!
  printf("Secret message successfully hidden in image!\n");

  return 0;
}