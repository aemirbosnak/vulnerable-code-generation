#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int read_size;

  printf("Enter the message: ");
  read_size = fscanf(stdin, "%s", buffer);

  if (read_size == -1) {
    printf("Error reading message.\n");
  } else {
    printf("Message received: %s\n", buffer);
  }

  return 0;
}
