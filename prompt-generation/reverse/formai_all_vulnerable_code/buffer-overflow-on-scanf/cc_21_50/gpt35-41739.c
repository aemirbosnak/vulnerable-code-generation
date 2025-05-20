//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 50

int main() {
  char filename[MAX_FILENAME_LENGTH];
  int choice;
  FILE *fileptr;
  unsigned char *image_data;
  int width, height;
  int r, g, b;
  int x, y;

  // prompt the user to enter the filename of the image to edit
  printf("Enter the filename of the image to edit (including the extension): ");
  scanf("%s", filename);

  // open the file
  fileptr = fopen(filename, "rb");

  if (fileptr == NULL) {
    printf("Error: could not open file.\n");
    return 1;
  }

  // read the image width and height from the file
  fread(&width, sizeof(int), 1, fileptr);
  fread(&height, sizeof(int), 1, fileptr);

  // allocate memory for the image data
  image_data = (unsigned char*)malloc(width * height * 3);

  // read the image data from the file
  fread(image_data, sizeof(unsigned char), width * height * 3, fileptr);

  // close the file
  fclose(fileptr);

  // display the original image
  printf("\nOriginal Image:\n");

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      r = image_data[(y * width + x) * 3];
      g = image_data[(y * width + x) * 3 + 1];
      b = image_data[(y * width + x) * 3 + 2];

      printf("(%d, %d, %d) ", r, g, b);
    }

    printf("\n");
  }

  // prompt the user to choose an edit option
  printf("\nSelect an edit option:\n");
  printf("1. Invert Colors\n");
  printf("2. Convert to Grayscale\n");
  printf("3. Sepia Tone\n");
  printf("4. Exit\n");
  printf("Choice: ");
  scanf("%d", &choice);

  // perform the chosen edit operation
  switch (choice) {
    case 1: {
      // invert colors
      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = 255 - image_data[(y * width + x) * 3];
          g = 255 - image_data[(y * width + x) * 3 + 1];
          b = 255 - image_data[(y * width + x) * 3 + 2];

          image_data[(y * width + x) * 3] = r;
          image_data[(y * width + x) * 3 + 1] = g;
          image_data[(y * width + x) * 3 + 2] = b;
        }
      }

      // save the modified image data to a new file
      fileptr = fopen("inverted_colors.bin", "wb");

      if (fileptr == NULL) {
        printf("Error: could not open file.\n");
        return 1;
      }

      fwrite(&width, sizeof(int), 1, fileptr);
      fwrite(&height, sizeof(int), 1, fileptr);
      fwrite(image_data, sizeof(unsigned char), width * height * 3, fileptr);

      fclose(fileptr);

      // display the modified image
      printf("\nModified Image (Inverted Colors):\n");

      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = image_data[(y * width + x) * 3];
          g = image_data[(y * width + x) * 3 + 1];
          b = image_data[(y * width + x) * 3 + 2];

          printf("(%d, %d, %d) ", r, g, b);
        }

        printf("\n");
      }

      break;
    }

    case 2: {
      // convert to grayscale
      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = image_data[(y * width + x) * 3];
          g = image_data[(y * width + x) * 3 + 1];
          b = image_data[(y * width + x) * 3 + 2];
          int gray = (r + g + b) / 3;

          image_data[(y * width + x) * 3] = gray;
          image_data[(y * width + x) * 3 + 1] = gray;
          image_data[(y * width + x) * 3 + 2] = gray;
        }
      }

      // save the modified image data to a new file
      fileptr = fopen("grayscale.bin", "wb");

      if (fileptr == NULL) {
        printf("Error: could not open file.\n");
        return 1;
      }

      fwrite(&width, sizeof(int), 1, fileptr);
      fwrite(&height, sizeof(int), 1, fileptr);
      fwrite(image_data, sizeof(unsigned char), width * height * 3, fileptr);

      fclose(fileptr);

      // display the modified image
      printf("\nModified Image (Grayscale):\n");

      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = image_data[(y * width + x) * 3];
          g = image_data[(y * width + x) * 3 + 1];
          b = image_data[(y * width + x) * 3 + 2];

          printf("(%d, %d, %d) ", r, g, b);
        }

        printf("\n");
      }

      break;
    }

    case 3: {
      // apply sepia tone
      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = image_data[(y * width + x) * 3];
          g = image_data[(y * width + x) * 3 + 1];
          b = image_data[(y * width + x) * 3 + 2];

          int tr = (int)(0.393 * r + 0.769 * g + 0.189 * b);
          int tg = (int)(0.349 * r + 0.686 * g + 0.168 * b);
          int tb = (int)(0.272 * r + 0.534 * g + 0.131 * b);

          if (tr > 255) {
            r = 255;
          } else {
            r = tr;
          }

          if (tg > 255) {
            g = 255;
          } else {
            g = tg;
          }

          if (tb > 255) {
            b = 255;
          } else {
            b = tb;
          }

          image_data[(y * width + x) * 3] = r;
          image_data[(y * width + x) * 3 + 1] = g;
          image_data[(y * width + x) * 3 + 2] = b;
        }
      }

      // save the modified image data to a new file
      fileptr = fopen("sepia_tone.bin", "wb");

      if (fileptr == NULL) {
        printf("Error: could not open file.\n");
        return 1;
      }

      fwrite(&width, sizeof(int), 1, fileptr);
      fwrite(&height, sizeof(int), 1, fileptr);
      fwrite(image_data, sizeof(unsigned char), width * height * 3, fileptr);

      fclose(fileptr);

      // display the modified image
      printf("\nModified Image (Sepia Tone):\n");

      for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
          r = image_data[(y * width + x) * 3];
          g = image_data[(y * width + x) * 3 + 1];
          b = image_data[(y * width + x) * 3 + 2];

          printf("(%d, %d, %d) ", r, g, b);
        }

        printf("\n");
      }

      break;
    }

    default: {
      // exit the program
      return 0;
    }
  }

  // free the memory allocated for the image data
  free(image_data);

  // exit the program
  return 0;
}