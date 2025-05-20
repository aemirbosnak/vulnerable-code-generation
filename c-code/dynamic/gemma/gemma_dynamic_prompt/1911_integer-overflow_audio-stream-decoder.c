#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int sample_value = 0x80000000;
  int decoded_value = sample_value * 2;

  printf("Original value: %x\n", sample_value);
  printf("Decoded value: %x\n", decoded_value);

  if (decoded_value > 0x7FFFFFFF)
  {
    printf("Overflow!");
  }

  return 0;
}
