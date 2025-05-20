#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[10];

int main() {
  printf("Enter a message: ");
  scanf("%s", buffer);

  printf("Your message is: %s\n", buffer);

  return 0;
}
