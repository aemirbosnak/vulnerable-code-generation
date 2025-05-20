//FormAI DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100*1024*1024

int main(int argc, char *argv[]) {
  FILE *input_image, *output_image, *input_file;
  long int input_file_size;
  unsigned char *input_image_buffer, *output_image_buffer, *input_file_buffer;
  int bytes_to_encode, i, j, k, l, m, n, bit;
  
  if(argc != 4) {
    printf("Usage: %s <input image> <output image> <input file>\n", argv[0]);
    return 1;
  }
  
  input_image = fopen(argv[1], "rb");
  if(input_image == NULL) {
    printf("Error opening input image\n");
    return 1;
  }
  
  output_image = fopen(argv[2], "wb");
  if(output_image == NULL) {
    printf("Error opening output image\n");
    fclose(input_image);
    return 1;
  }
  
  input_file = fopen(argv[3], "rb");
  if(input_file == NULL) {
    printf("Error opening input file\n");
    fclose(input_image);
    fclose(output_image);
    return 1;
  }
  
  fseek(input_file, 0, SEEK_END);
  input_file_size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);
  
  if(input_file_size > MAX_FILE_SIZE) {
    printf("Input file too large\n");
    fclose(input_image);
    fclose(output_image);
    fclose(input_file);
    return 1;
  }
  
  input_image_buffer = (unsigned char *) malloc(input_file_size);
  if(input_image_buffer == NULL) {
    printf("Error allocating memory for input image buffer\n");
    fclose(input_image);
    fclose(output_image);
    fclose(input_file);
    return 1;
  }
  
  fread(input_image_buffer, 1, input_file_size, input_image);
  fclose(input_image);
  
  output_image_buffer = (unsigned char *) malloc(input_file_size);
  if(output_image_buffer == NULL) {
    printf("Error allocating memory for output image buffer\n");
    fclose(output_image);
    fclose(input_file);
    free(input_image_buffer);
    return 1;
  }
  
  memcpy(output_image_buffer, input_image_buffer, input_file_size);
  
  input_file_buffer = (unsigned char *) malloc(input_file_size + 1);
  if(input_file_buffer == NULL) {
    printf("Error allocating memory for input file buffer\n");
    fclose(output_image);
    fclose(input_file);
    free(input_image_buffer);
    free(output_image_buffer);
    return 1;
  }
  
  fread(input_file_buffer, 1, input_file_size, input_file);
  fclose(input_file);
  
  for(i = 0; i < input_file_size; i++) {
    bytes_to_encode = input_file_buffer[i];
    for(j = 0; j < 8; j++) {
      bit = ((bytes_to_encode >> (8 - (j + 1))) & 0x01);
      l = (i * 8) + j;
      k = l / 8;
      m = l % 8;
      n = output_image_buffer[k] & ~(0x01 << (8 - (m + 1)));
      if(bit != 0)
        output_image_buffer[k] = n | (0x01 << (8 - (m + 1)));
      else
        output_image_buffer[k] = n;
    }
  }
  
  fwrite(output_image_buffer, 1, input_file_size, output_image);
  
  free(input_image_buffer);
  free(output_image_buffer);
  free(input_file_buffer);
  
  printf("Image steganography completed successfully\n");
  
  return 0;
}