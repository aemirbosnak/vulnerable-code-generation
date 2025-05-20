#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  void *ptr = malloc(10);
  free(ptr);
  printf("%p", ptr); // Use after free vulnerability
  return 0;
}
