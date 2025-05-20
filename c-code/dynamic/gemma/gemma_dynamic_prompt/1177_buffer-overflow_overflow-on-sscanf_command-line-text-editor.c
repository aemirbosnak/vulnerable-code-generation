#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  int len = 0;

  printf("Enter text: ");
  scanf("%s", buffer);

  len = strlen(buffer) + 1;
  if (len > 1024) {
    printf("Error: Text too long.\n");
  } else {
    printf("Your text: %s\n", buffer);
  }

  return 0;
}
