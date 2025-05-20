//FormAI DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>

void main() {
  FILE *image;
  char filename[20], choice;
  int width, height, b;
  
  printf("Enter image file name: ");
  scanf("%s", filename);
  
  image = fopen(filename, "rb");
  
  if (!image) {
    printf("Error opening file.");
    return;
  }
  
  printf("Image file opened successfully!\n");
  printf("Enter image width: ");
  scanf("%d", &width);
  printf("Enter image height: ");
  scanf("%d", &height);
  
  b = width * height;
  
  unsigned char *data = (unsigned char*) malloc(b * sizeof(unsigned char));
  
  fread(data, sizeof(unsigned char), b, image);
  
  printf("Image data read successfully!\n");
  
  printf("Choose an operation to perform on the image:\n");
  printf("1. Grayscale conversion\n");
  printf("2. Invert colors\n");
  printf("3. Brightness adjustment\n");
  printf("4. Exit\n");
  
  fflush(stdin);
  scanf("%c", &choice);
  
  switch(choice) {
    case '1':
      printf("Performing grayscale conversion...\n");
      for (int i = 0; i < b; i++) {
        data[i] = (data[i*3] + data[i*3+1] + data[i*3+2]) / 3;
      }
      printf("Grayscale conversion complete!\n");
      break;
    case '2':
      printf("Inverting colors...\n");
      for (int i = 0; i < b; i++) {
        data[i*3] = 255 - data[i*3];
        data[i*3+1] = 255 - data[i*3+1];
        data[i*3+2] = 255 - data[i*3+2];
      }
      printf("Color inversion complete!\n");
      break;
    case '3':
      printf("Enter brightness adjustment value (between -255 and 255): ");
      int brightness;
      scanf("%d", &brightness);
      printf("Adjusting brightness...\n");
      for (int i = 0; i < b; i++) {
        data[i*3] = (data[i*3] + brightness > 255) ? 255 : data[i*3] + brightness;
        data[i*3+1] = (data[i*3+1] + brightness > 255) ? 255 : data[i*3+1] + brightness;
        data[i*3+2] = (data[i*3+2] + brightness > 255) ? 255 : data[i*3+2] + brightness;
      }
      printf("Brightness adjustment complete!\n");
      break;
    case '4':
      printf("Exiting program...\n");
      return;
    default:
      printf("Invalid choice. Exiting program...\n");
      return;
  }
  
  FILE *out = fopen("output.bmp", "wb");
  
  fwrite(data, sizeof(unsigned char), b, out);
  
  printf("Output file written successfully!\n");
  
  fclose(image);
  fclose(out);
  free(data);
}