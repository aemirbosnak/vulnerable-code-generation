#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **a = NULL;
  *a = "hello";
  printf("%s", *a);
  free(a);
  return 0;
}
