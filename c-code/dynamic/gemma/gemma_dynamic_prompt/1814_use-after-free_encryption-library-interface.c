#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  int *ptr = NULL;
  ptr = malloc(10);
  strcpy(ptr, "Secret message");
  free(ptr);
  printf("%s", ptr);
  return 0;
}
