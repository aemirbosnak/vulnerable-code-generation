#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int i = 0;
  int num_bytes = 0;

  printf("Enter HTTP request: ");
  fgets(buffer, 1024, stdin);

  num_bytes = strlen(buffer);

  for (i = 0; i < num_bytes; i++) {
    if (buffer[i] >= 'a' && buffer[i] <= 'z') {
      buffer[i] = buffer[i] - 32;
    }
  }

  printf("Modified request: %s", buffer);

  return 0;
}
