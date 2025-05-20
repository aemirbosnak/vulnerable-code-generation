#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[16];
  printf("Enter a message: ");
  scanf("%s", buffer);

  // Exploit buffer overflow vulnerability
  sprintf(buffer, "The message is: %s", buffer);

  printf("Your encrypted message is: %s", buffer);

  return 0;
}
