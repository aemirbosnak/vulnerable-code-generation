#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  int index = 0;

  printf("Enter a command: ");
  scanf("%s", buffer);

  while (index < 10) {
    buffer[index] = buffer[index - 1];
    index++;
  }

  printf("Here is your modified command: %s", buffer);

  return 0;
}
