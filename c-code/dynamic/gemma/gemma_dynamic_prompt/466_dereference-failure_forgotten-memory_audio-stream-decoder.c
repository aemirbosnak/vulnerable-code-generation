#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = NULL;
  char data[1024];

  FILE *file = fopen("audio.wav", "rb");
  fread(data, 1, 1024, file);

  ptr = (int *)data;
  printf("%d", *ptr);

  fclose(file);
  return 0;
}
