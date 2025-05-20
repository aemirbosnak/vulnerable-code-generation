#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = NULL;
  int size = 0;
  scanf(" %*c", &buf); // Overflow on scanf
  size = atoi(buf);
  free(buf);
  return 0;
}
