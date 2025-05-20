#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char key[1024] = "This is a secret key";

  printf("Enter a message: ");
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[10] = key[0];

  printf("Your message is: %s", buffer);

  return 0;
}
