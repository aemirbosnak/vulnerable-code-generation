//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 255

int main()
{
  FILE *input_file;
  FILE *output_file;
  
  char input_filename[100];
  char output_filename[100];
  
  int rows, cols, max_val;
  int row, col;
  
  // Prompt user for input and output filenames
  printf("Enter input filename: ");
  scanf("%s", input_filename);
  
  printf("Enter output filename: ");
  scanf("%s", output_filename);
  
  // Open input file in read binary mode
  input_file = fopen(input_filename, "rb");
  
  if (input_file == NULL)
  {
    printf("Error opening file: %s", input_filename);
    exit(1);
  }
  
  // Open output file in write binary mode
  output_file = fopen(output_filename, "wb");
  
  if (output_file == NULL)
  {
    printf("Error opening file: %s", output_filename);
    exit(1);
  }
  
  // Read image header
  fscanf(input_file, "P5\n%d %d\n%d\n", &cols, &rows, &max_val);
  
  // Allocate memory for input and output image arrays
  unsigned char **input_image = (unsigned char **) malloc(rows * sizeof(unsigned char *));
  unsigned char **output_image = (unsigned char **) malloc(rows * sizeof(unsigned char *));
  
  for (row = 0; row < rows; row++)
  {
    input_image[row] = (unsigned char *) malloc(cols * sizeof(unsigned char));
    output_image[row] = (unsigned char *) malloc(cols * sizeof(unsigned char));
  }
  
  // Read input image
  fread(input_image[0], sizeof(unsigned char), rows * cols, input_file);
  
  // Flip image vertically
  for (row = 0; row < rows; row++)
  {
    for (col = 0; col < cols; col++)
    {
      output_image[row][col] = input_image[rows - row - 1][col];
    }
  }
  
  // Adjust image brightness and contrast
  float brightness_factor = 1.5;
  float contrast_factor = 0.8;
  
  for (row = 0; row < rows; row++)
  {
    for (col = 0; col < cols; col++)
    {
      int pixel_value = (int) output_image[row][col];
      pixel_value = (int) (brightness_factor * pixel_value);
      pixel_value = (int) ((pixel_value - MAX_VALUE/2) * contrast_factor + MAX_VALUE/2);
      
      if (pixel_value < 0)
      {
        pixel_value = 0;
      }
      
      if (pixel_value > MAX_VALUE)
      {
        pixel_value = MAX_VALUE;
      }
      
      output_image[row][col] = (unsigned char) pixel_value;
    }
  }
  
  // Write output image
  fprintf(output_file, "P5\n%d %d\n%d\n", cols, rows, max_val);
  fwrite(output_image[0], sizeof(unsigned char), rows * cols, output_file);
  
  // Free memory and close files
  for (row = 0; row < rows; row++)
  {
    free(input_image[row]);
    free(output_image[row]);
  }
  
  free(input_image);
  free(output_image);
  
  fclose(input_file);
  fclose(output_file);
  
  printf("Image processed successfully!\n");
  
  return 0;
}