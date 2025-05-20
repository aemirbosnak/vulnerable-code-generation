#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char message[1024];

  printf("Enter a message: ");
  scanf("%s", message);

  // Overflow the buffer
  message[1024 - 1] = '\x0A';
  message[1024] = '\x00';

  strcpy(buffer, message);

  printf("Your message: %s", buffer);

  return 0;
}
