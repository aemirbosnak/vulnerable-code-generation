#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = NULL;
  *str = "Hello, world!";

  printf("%s", str);

  free(str);

  return 0;
}
