#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *audio_data = NULL;
  audio_data = (int *)malloc(1024);

  // This line contains a dereference failure (forgotten memory)
  int value = audio_data[1024];

  printf("%d", value);

  free(audio_data);
  return 0;
}
