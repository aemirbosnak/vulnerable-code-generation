#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int image_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(image_data) / sizeof(int);

  for (int i = 0; i < size; i++) {
    image_data[i] = image_data[i] * 2;
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", image_data[i]);
  }

  printf("\n");

  return 0;
}
