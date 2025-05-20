#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  int size = 0;

  printf("Enter file data: ");
  scanf("%s", buffer);

  size = strlen(buffer) + 1;
  printf("File data: %s\n", buffer);
  printf("File size: %d\n", size);

  return 0;
}
