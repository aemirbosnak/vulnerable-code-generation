#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char buffer[16];
  int len;

  printf("Enter text: ");
  len = gets(buffer);

  if (len > 15) {
    printf("Error: input too long.\n");
  } else {
    printf("Your text: %s\n", buffer);
  }

  return 0;
}
