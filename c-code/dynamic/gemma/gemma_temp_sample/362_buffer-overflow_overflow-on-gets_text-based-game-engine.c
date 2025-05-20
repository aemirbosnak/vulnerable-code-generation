#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  gets(buffer);

  if (strlen(buffer) >= 10) {
    buffer[9] = '\0';
  }

  printf("%s\n", buffer);
  return 0;
}
