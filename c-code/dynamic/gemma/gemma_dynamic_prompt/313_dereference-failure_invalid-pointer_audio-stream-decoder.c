#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* p_audio_data = NULL;
  p_audio_data = (int*)malloc(10 * sizeof(int));
  if (p_audio_data == NULL) {
    return -1;
  }

  // Invalid pointer dereference
  *p_audio_data = 42;

  free(p_audio_data);
  return 0;
}
