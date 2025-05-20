#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  void *ptr = malloc(10);
  free(ptr);
  strcpy(ptr, "Secret message");
  printf("%s", ptr);
  return 0;
}
