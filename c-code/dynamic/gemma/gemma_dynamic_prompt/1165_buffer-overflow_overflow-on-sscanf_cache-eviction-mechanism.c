#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  char input[1024];

  printf("Enter key: ");
  scanf("%s", input);

  if (strlen(input) > 10) {
    printf("Error: Input too long.\n");
  } else {
    strcpy(buffer, input);
    printf("Key stored: %s\n", buffer);
  }

  return 0;
}
