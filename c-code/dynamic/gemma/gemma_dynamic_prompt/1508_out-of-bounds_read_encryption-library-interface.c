#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *data = malloc(10);
  data[0] = 'A';
  data[1] = 'B';
  data[2] = 'C';
  data[3] = 'D';
  data[4] = 'E';
  data[5] = '\0';

  // Out of bounds read vulnerability
  char *vulnerable_data = data + 10;
  printf("%s", vulnerable_data);

  free(data);
  return 0;
}
