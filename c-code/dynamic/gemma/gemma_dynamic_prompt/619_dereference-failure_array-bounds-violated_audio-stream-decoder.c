#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i = 0;
  char *audio_data = malloc(1024);
  audio_data[0] = 0x5A;
  audio_data[1] = 0xBA;

  // Vulnerable code: Array bounds violation
  audio_data[1024] = 0xCA;

  free(audio_data);
  return 0;
}
