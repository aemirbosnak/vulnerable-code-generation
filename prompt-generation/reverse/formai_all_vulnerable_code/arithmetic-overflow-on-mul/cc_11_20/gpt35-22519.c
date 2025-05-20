//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  
  // Declare variables
  char filename[50];
  char option;
  int width, height, maxval;

  // Prompt user for filename
  printf("Enter filename: ");
  scanf("%s", filename);

  // Open file for reading
  FILE *f = fopen(filename, "rb");

  // Check if file exists
  if (f == NULL) {
    printf("File does not exist.");
    return 1;
  }

  // Read header information
  char magic[3];
  fscanf(f, "%s\n", magic);

  // Check if file is P3 or P6 format
  if (strcasecmp(magic, "P3") != 0 && strcasecmp(magic, "P6") != 0) {
    printf("Invalid file format. Must be P3 or P6.");
    return 1;
  }

  // Get image width, height, and maximum RGB value
  fscanf(f, "%d %d\n%d\n", &width, &height, &maxval);

  // Allocate memory for pixel data
  unsigned char *pixels = (unsigned char*) malloc(width * height * 3);

  // Read pixel data
  fread(pixels, sizeof(unsigned char), width * height * 3, f);

  // Close file
  fclose(f);

  // Prompt user for editing option
  printf("Choose an option:\n");
  printf("a. Convert to grayscale\n");
  printf("b. Flip horizontally\n");
  printf("c. Flip vertically\n");
  scanf(" %c", &option);

  // Perform editing option
  switch (tolower(option)) {
    case 'a':
      for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char grayscale = (pixels[i] + pixels[i+1] + pixels[i+2]) / 3;
        pixels[i] = grayscale;
        pixels[i+1] = grayscale;
        pixels[i+2] = grayscale;
      }
      break;
    case 'b':
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
          int index1 = (i * width + j) * 3;
          int index2 = (i * width + (width - j - 1)) * 3;
          unsigned char temp[3];
          memcpy(temp, pixels + index1, 3);
          memcpy(pixels + index1, pixels + index2, 3);
          memcpy(pixels + index2, temp, 3);
        }
      }
      break;
    case 'c':
      for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
          int index1 = (i * width + j) * 3;
          int index2 = ((height - i - 1) * width + j) * 3;
          unsigned char temp[3];
          memcpy(temp, pixels + index1, 3);
          memcpy(pixels + index1, pixels + index2, 3);
          memcpy(pixels + index2, temp, 3);
        }
      }
      break;
    default:
      printf("Invalid option.");
      return 1;
  }

  // Open file for writing
  f = fopen("edited.ppm", "wb");

  // Write header information
  fprintf(f, "%s\n%d %d\n%d\n", magic, width, height, maxval);

  // Write pixel data
  fwrite(pixels, sizeof(unsigned char), width * height * 3, f);

  // Close file
  fclose(f);

  // Free memory
  free(pixels);

  // Exit program
  printf("Image edited successfully.");
  return 0;
}