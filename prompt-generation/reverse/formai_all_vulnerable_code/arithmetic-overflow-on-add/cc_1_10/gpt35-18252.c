//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHANNELS 3

typedef unsigned char BYTE;

BYTE* read_bmp(char* filename, int* width, int* height, int* channels) {
  FILE* f = fopen(filename, "rb");
  
  BYTE info[54];
  fread(info, sizeof(BYTE), 54, f); // read the 54-byte header
  
  int img_size = *(int*)&info[0x22];
  *width = *(int*)&info[0x12];
  *height = *(int*)&info[0x16];
  
  // extract image data
  BYTE* data = (BYTE*) malloc(img_size);
  fread(data, sizeof(BYTE), img_size, f);

  fclose(f);

  *channels = CHANNELS;
  
  return data;
}

void write_bmp(char* filename, int width, int height, int channels, BYTE* data) {
  FILE* f = fopen(filename, "wb");

  BYTE header[54] = {
    'B','M', // magic
    0,0,0,0, // size in bytes
    0,0,0,0, // reserved
    54,0,0,0, // offset to start of pixel data
    40,0,0,0, // info hd size
    0,0,0,0, // width
    0,0,0,0, // height
    1,0,     // number color planes
    8,0,     // bits per pixel
    0,0,0,0, // compression is none
    0,0,0,0, // image bits size
    0x13,0x0B,0,0, // horz resoluition in pixel / m
    0x13,0x0B,0,0, // vert resolutions (0x03C3 = 96 dpi, 0x0B13 = 72 dpi)
    0,0,0,0, // #colors in pallete
    0,0,0,0, // #important colors
  };
  *(int*)&header[0x2] = width * height * channels + 54; //file size - 54 bytes header
  *(int*)&header[0x12] = width;
  *(int*)&header[0x16] = height;

  fwrite(header, sizeof(BYTE), 54, f);
  fwrite(data, sizeof(BYTE), width*height*channels, f);

  fclose(f);
}

BYTE* flip_image(BYTE* data, int width, int height, int channels) {
  BYTE* flipped_data = (BYTE*) malloc(width*height*channels);

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      for(int k = 0; k < channels; k++) {
        flipped_data[(((height - i - 1)*width) + j)*channels + k] = data[(i*width + j)*channels + k];
      }
    }
  }

  return flipped_data;
}

BYTE* adjust_brightness_and_contrast(BYTE* data, int width, int height, int channels,
                                     float brightness_factor, float contrast_factor) {
  BYTE* new_data = (BYTE*) malloc(width*height*channels);

  float brightness_offset = brightness_factor * 255;
  float contrast_coeff = (contrast_factor * 255 - 128) / 128 + 1;

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      for(int k = 0; k < channels; k++) {
        float pixel_value = data[(i*width + j)*channels + k];
        pixel_value = contrast_coeff * (pixel_value - 128) + 128 + brightness_offset;
        if(pixel_value > 255) pixel_value = 255;
        if(pixel_value < 0) pixel_value = 0;
        new_data[(i*width + j)*channels + k] = (BYTE) pixel_value;
      }
    }
  }

  return new_data;
}

int main(int argc, char** argv) {
  if(argc < 4) {
    printf("Usage: %s input_file output_file brightness_factor contrast_factor\n", argv[0]);
    return -1;
  }

  int width, height, channels;
  BYTE* data = read_bmp(argv[1], &width, &height, &channels);

  // Flipping the image
  printf("Flipping the image...\n");
  BYTE* flipped_data = flip_image(data, width, height, channels);
  
  // Adjusting brightness and contrast
  float brightness_factor = atof(argv[3]);
  float contrast_factor = atof(argv[4]);
  printf("Adjusting brightness and contrast with factors %.2f and %.2f...\n",
         brightness_factor, contrast_factor);
  BYTE* adjusted_data = adjust_brightness_and_contrast(flipped_data, width, height, channels,
                                                       brightness_factor, contrast_factor);

  printf("Writing result to file %s...\n", argv[2]);
  write_bmp(argv[2], width, height, channels, adjusted_data);

  free(data);
  free(flipped_data);
  free(adjusted_data);

  return 0;
}