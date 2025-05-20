#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *audio_data = (int *)malloc(10 * sizeof(int));
  audio_data[10] = 5; // Array bounds violation

  printf("%d", audio_data[10]);

  free(audio_data);
  return 0;
}
