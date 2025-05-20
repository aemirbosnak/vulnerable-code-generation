#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *key = "Secret key";
  char *message = "This is a message";

  // Out-of-bounds read vulnerability
  char *vulnerable_data = (char *) malloc(10);
  vulnerable_data[0] = key[0];
  vulnerable_data[1] = key[1];
  vulnerable_data[2] = key[2];
  vulnerable_data[3] = key[3];
  vulnerable_data[4] = key[4];
  vulnerable_data[5] = key[5];
  vulnerable_data[6] = key[6];
  vulnerable_data[7] = key[7];
  vulnerable_data[8] = key[8];
  vulnerable_data[9] = key[9];

  printf("Original message: %s", message);
  printf("\nEncrypeted message: %s", vulnerable_data);

  free(vulnerable_data);
  return 0;
}
