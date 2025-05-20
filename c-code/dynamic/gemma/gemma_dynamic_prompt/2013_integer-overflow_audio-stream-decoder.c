#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int sample_value = 2147483647;
  int decoded_value = sample_value * 2;
  printf("Decoded value: %d\n", decoded_value);
  return 0;
}
