#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **buffer = NULL;
  int size = 0;
  char data[1024];

  printf("Enter data: ");
  scanf("%s", data);

  buffer = realloc(buffer, size + 1);
  buffer[size++] = data;

  printf("Log entry: %s\n", buffer[size - 1]);

  free(buffer);
  return 0;
}
