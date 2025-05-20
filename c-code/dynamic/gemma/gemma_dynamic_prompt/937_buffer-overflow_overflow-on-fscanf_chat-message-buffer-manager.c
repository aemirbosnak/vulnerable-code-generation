#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int read_size = 0;

  printf("Enter a message: ");
  scanf("%s", buffer);

  read_size = strlen(buffer) + 1;
  buffer[read_size - 1] = '\0';

  printf("Your message: %s\n", buffer);

  return 0;
}
