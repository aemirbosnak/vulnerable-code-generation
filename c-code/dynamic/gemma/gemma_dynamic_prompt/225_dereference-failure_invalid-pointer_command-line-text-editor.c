#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  *ptr = 'a';
  printf("%c", *ptr);
  free(ptr);
  return 0;
}
