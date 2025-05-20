#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  ptr = (char *)malloc(10);
  if (ptr == NULL) {
    return 1;
  }
  *ptr = 'a';
  printf("%c", *(ptr + 10)); // This line contains the dereference failure
  free(ptr);
  return 0;
}
