#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  printf("Enter a command: ");
  getline(buffer, size, stdin);

  // Out-of-bounds read vulnerability
  int index = atoi(buffer) + 10;
  char data = buffer[index];

  // Print the data
  printf("Data: %c", data);

  return 0;
}
