#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int i = 0;

  // Read input from the user
  printf("Enter a command: ");
  fgets(buffer, 1024, stdin);

  // Loop over the input buffer and print characters in reverse order
  for (i = strlen(buffer) - 1; i >= 0; i--) {
    printf("%c ", buffer[i]);
  }

  printf("\n");

  return 0;
}
