#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  ptr = (char *)malloc(10);
  *ptr = 'a';
  printf("%c", *(ptr - 1));
  free(ptr);
  return 0;
}
