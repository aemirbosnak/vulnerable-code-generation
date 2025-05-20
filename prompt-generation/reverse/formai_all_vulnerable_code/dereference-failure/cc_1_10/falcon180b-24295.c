//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

int main(int argc, char **argv) {
  char *input_file = argv[1];
  char *output_file = argv[2];
  char *message = argv[3];
  int message_length = strlen(message);

  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    fprintf(stderr, "Error opening input file.\n");
    exit(1);
  }

  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    fprintf(stderr, "Error opening output file.\n");
    exit(1);
  }

  int image_size = WIDTH * HEIGHT;
  unsigned char *image = malloc(image_size);
  if (image == NULL) {
    fprintf(stderr, "Error allocating memory for image.\n");
    exit(1);
  }

  fread(image, 1, image_size, input);
  fclose(input);

  // Embed message in image using LSB technique
  int index = 0;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int pixel_value = image[index];
      int bit_value = message[index % message_length] - 48;
      pixel_value = (pixel_value << 1) | bit_value;
      image[index] = pixel_value;
      index++;
    }
  }

  // Save watermarked image
  fwrite(image, 1, image_size, output);
  fclose(output);

  printf("Watermarking completed successfully.\n");
  return 0;
}