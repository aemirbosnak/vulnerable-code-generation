#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  return ptr;
}

int main() {
  char *buf = allocate(10);
  char input[100];

  printf("Enter a string: ");
  scanf("%s", input);

  // Overflow the buffer
  strcpy(buf, input);

  printf("Your string: %s", buf);

  free(buf);
  return 0;
}
