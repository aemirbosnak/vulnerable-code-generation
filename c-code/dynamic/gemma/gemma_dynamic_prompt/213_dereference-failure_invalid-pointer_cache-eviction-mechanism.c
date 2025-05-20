#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *ptr = NULL;
  ptr = (int *)malloc(10);
  *ptr = 10;
  printf("%d", *ptr);

  free(ptr);
  ptr = NULL;
  *ptr = 20; // This line will result in a dereference failure

  printf("%d", *ptr); // This line will crash
  return 0;
}
