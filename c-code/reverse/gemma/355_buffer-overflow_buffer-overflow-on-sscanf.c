#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  printf("Enter filename: ");
  scanf("%s", filename);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char buffer[1024];
  int width, height;
  fscanf(fp, "%d %d", &width, &height);

  if (fscanf(fp, "%s", buffer) != 1) {
    fclose(fp);
    perror("Error parsing image data");
    return 1;
  }

  fclose(fp);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel = buffer[y * width + x] & 0xFF;
      switch (pixel) {
        case 0:
          printf(" ");
          break;
        case 255:
          printf("#");
          break;
        default:
          printf(".");
          break;
      }
    }
    printf("\n");
  }

  return 0;
}
