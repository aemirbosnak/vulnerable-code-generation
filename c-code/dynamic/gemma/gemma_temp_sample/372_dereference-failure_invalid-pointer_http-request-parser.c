#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *url = "example.com";
  char *ptr = NULL;

  ptr = (char *) malloc(strlen(url) + 1);
  strcpy(ptr, url);

  // Vulnerable dereference of a NULL pointer
  printf("%c", *(ptr + 10));

  free(ptr);
  return 0;
}
