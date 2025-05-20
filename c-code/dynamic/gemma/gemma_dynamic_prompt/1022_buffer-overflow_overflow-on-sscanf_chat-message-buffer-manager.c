#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char message[1024];

  printf("Enter your message: ");
  scanf("%s", message);

  // Exploit the buffer overflow vulnerability
  message[1024 - 1] = 'a';

  printf("Your message: %s", message);

  return 0;
}
