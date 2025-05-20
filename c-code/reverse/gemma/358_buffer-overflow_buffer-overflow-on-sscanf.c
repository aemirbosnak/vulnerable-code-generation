#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  scanf("Enter image filename: ", filename);

  FILE* file = fopen(filename, "r");
  if (!file) {
    return 1;
  }

  char buffer[1024];
  fscanf(file, "%d %d", &buffer, &buffer);

  int width = atoi(buffer);
  int height = atoi(buffer + 4);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel = fgetc(file);
      printf("%c ", pixel > 127 ? ' ' : '.');
    }
    printf("\n");
  }

  fclose(file);
  return 0;
}
