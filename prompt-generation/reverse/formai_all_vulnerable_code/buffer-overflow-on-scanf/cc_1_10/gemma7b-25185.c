//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  int img_width, img_height;
  printf("Enter image width: ");
  scanf("%d", &img_width);

  printf("Enter image height: ");
  scanf("%d", &img_height);

  int **img_data = (int **)malloc(img_height * sizeof(int *));
  for (int h = 0; h < img_height; h++) {
    img_data[h] = (int *)malloc(img_width * sizeof(int));
  }

  printf("Enter image data (separated by commas): ");
  char input[1024];
  scanf("%s", input);

  int i = 0;
  for (int h = 0; h < img_height; h++) {
    for (int w = 0; w < img_width; w++) {
      img_data[h][w] = atoi(&input[i]);
      i++;
    }
  }

  for (int h = 0; h < img_height; h++) {
    for (int w = 0; w < img_width; w++) {
      switch (img_data[h][w]) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("#");
          break;
        default:
          printf("!");
          break;
      }
    }
    printf("\n");
  }

  free(img_data);

  return 0;
}