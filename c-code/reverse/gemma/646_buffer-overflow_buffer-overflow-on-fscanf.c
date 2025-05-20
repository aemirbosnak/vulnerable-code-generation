#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("image.txt", "r");
  if (file == NULL) {
    return 1;
  }

  int width, height;
  fscanf(file, "%d %d", &width, &height);

  int* image = (int*)malloc(width * height * sizeof(int));
  if (image == NULL) {
    fclose(file);
    return 1;
  }

  fscanf(file, "%d ", image);

  fclose(file);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", image[x * height + y] + 48);
    }
    printf("\n");
  }

  free(image);

  return 0;
}
