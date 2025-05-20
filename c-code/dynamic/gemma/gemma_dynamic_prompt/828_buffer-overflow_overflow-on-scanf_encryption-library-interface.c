#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[16];

  printf("Enter a secret message: ");
  scanf("%s", buffer);

  // Buffer overflow
  sprintf(buffer, "Secret message: %s", buffer);

  printf("Your secret message is: %s", buffer);

  return 0;
}
