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
  char *buffer = allocate(10);
  printf("Enter a string: ");
  scanf("%s", buffer);

  // Overflow the buffer to trigger the vulnerability
  char overflow_data[1000] = "This is an example string that will cause a buffer overflow";
  memcpy(buffer, overflow_data, 1000);

  free(buffer);
  return 0;
}
