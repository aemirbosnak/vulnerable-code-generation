#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* data = NULL;
  data = malloc(10);
  if (data == NULL) {
    return 1;
  }

  // Use after free vulnerability
  free(data);
  data[0] = 'a';

  printf("%c", data[0]);

  return 0;
}
