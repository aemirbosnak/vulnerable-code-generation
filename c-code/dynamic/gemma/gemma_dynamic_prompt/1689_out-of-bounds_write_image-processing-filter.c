#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int img_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int img_size = 10;

  // Out-of-bounds write
  img_data[img_size] = 11;

  printf("Image data: ");
  for (int i = 0; i < img_size; i++) {
    printf("%d ", img_data[i]);
  }

  printf("\n");

  return 0;
}
