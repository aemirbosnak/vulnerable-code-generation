#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* str = malloc(10);
  str[0] = 'H';
  str[1] = 'T';
  str[2] = 'T';
  str[3] = 'P';
  str[4] = 'A';
  str[5] = 'R';
  str[6] = 'G';
  str[7] = 'E';
  str[8] = 'T';
  str[9] = '\0';

  printf("%s", str);

  free(str);

  return 0;
}
