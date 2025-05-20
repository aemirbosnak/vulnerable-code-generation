#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char *ptr = NULL;
  *ptr = 'a';

  printf("%c", *ptr);

  return 0;
}
