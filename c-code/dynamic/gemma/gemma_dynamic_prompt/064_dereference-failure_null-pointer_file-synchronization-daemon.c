#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **arr = NULL;
  arr = (char**)malloc(10);
  *arr = NULL;
  printf("%s", *arr);
  return 0;
}
