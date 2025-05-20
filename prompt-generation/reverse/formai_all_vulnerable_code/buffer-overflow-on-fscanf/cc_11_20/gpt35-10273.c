//FormAI DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Initializing variables
  int option = 0, width = 0, height = 0, max_value = 0;
  char filter_option = '\0';
  
  // Opening the input file
  FILE *input = fopen("input.ppm", "rb");
  if (input == NULL) {
    printf("ERROR: Unable to open input file!\n");
    return 1;
  }
  
  // Reading the header of the input file
  char magic_number[3];
  fscanf(input, "%2s %d %d %d", magic_number, &width, &height, &max_value);
  
  // Checking if the input file is in the correct format
  if (magic_number[0] != 'P' || magic_number[1] != '6') {
    printf("ERROR: Invalid input file format!\n");
    return 1;
  }
  
  // Creating and opening the output file
  FILE *output = fopen("output.ppm", "wb");
  if (output == NULL) {
    printf("ERROR: Unable to create output file!\n");
    return 1;
  }
  
  // Writing the header of the output file
  fprintf(output, "P6\n%d %d\n%d\n", width, height, max_value);
  
  // Prompting the user for a filter option
  printf("Please choose a filter option:\n");
  printf("a. Black and white\n");
  printf("b. Negative\n");
  printf("c. Sepia\n");
  printf("d. Inverted sepia\n");
  scanf(" %c", &filter_option);
  
  // Applying the selected filter option
  switch(filter_option) {
    case 'a': {
      // Black and white filter
      
      // Iterating through each pixel
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          // Reading the pixel values
          unsigned char r, g, b;
          fread(&r, 1, 1, input);
          fread(&g, 1, 1, input);
          fread(&b, 1, 1, input);
          
          // Converting the pixel to black and white
          unsigned char gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;
          
          // Writing the processed pixel to the output file
          fwrite(&gray, 1, 1, output);
          fwrite(&gray, 1, 1, output);
          fwrite(&gray, 1, 1, output);
        }
      }
      
      break;
    }
    case 'b': {
      // Negative filter
      
      // Iterating through each pixel
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          // Reading the pixel values
          unsigned char r, g, b;
          fread(&r, 1, 1, input);
          fread(&g, 1, 1, input);
          fread(&b, 1, 1, input);
          
          // Converting the pixel to negative
          unsigned char neg_r = max_value - r;
          unsigned char neg_g = max_value - g;
          unsigned char neg_b = max_value - b;
          
          // Writing the processed pixel to the output file
          fwrite(&neg_r, 1, 1, output);
          fwrite(&neg_g, 1, 1, output);
          fwrite(&neg_b, 1, 1, output);
        }
      }
      
      break;
    }
    case 'c': {
      // Sepia filter
      
      // Iterating through each pixel
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          // Reading the pixel values
          unsigned char r, g, b;
          fread(&r, 1, 1, input);
          fread(&g, 1, 1, input);
          fread(&b, 1, 1, input);
          
          // Converting the pixel to sepia
          unsigned char sepia_r = (0.393 * r) + (0.769 * g) + (0.189 * b);
          unsigned char sepia_g = (0.349 * r) + (0.686 * g) + (0.168 * b);
          unsigned char sepia_b = (0.272 * r) + (0.534 * g) + (0.131 * b);
          
          // Writing the processed pixel to the output file
          fwrite(&sepia_r, 1, 1, output);
          fwrite(&sepia_g, 1, 1, output);
          fwrite(&sepia_b, 1, 1, output);
        }
      }
      
      break;
    }
    case 'd': {
      // Inverted sepia filter
      
      // Iterating through each pixel
      for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
          // Reading the pixel values
          unsigned char r, g, b;
          fread(&r, 1, 1, input);
          fread(&g, 1, 1, input);
          fread(&b, 1, 1, input);
          
          // Converting the pixel to inverted sepia
          unsigned char inv_sepia_r = max_value - ((0.393 * r) + (0.769 * g) + (0.189 * b));
          unsigned char inv_sepia_g = max_value - ((0.349 * r) + (0.686 * g) + (0.168 * b));
          unsigned char inv_sepia_b = max_value - ((0.272 * r) + (0.534 * g) + (0.131 * b));
          
          // Writing the processed pixel to the output file
          fwrite(&inv_sepia_r, 1, 1, output);
          fwrite(&inv_sepia_g, 1, 1, output);
          fwrite(&inv_sepia_b, 1, 1, output);
        }
      }
      
      break;
    }
    default: {
      printf("ERROR: Invalid filter option!\n");
      return 1;
    }
  }
  
  // Closing the input and output files
  fclose(input);
  fclose(output);
  
  printf("Filter successfully applied to the image!\n");
  
  return 0;
}