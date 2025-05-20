#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10] = "";
  char input[100] = "";

  printf("Enter a message: ");
  scanf("%s", input);

  if (strlen(input) > 10) {
    printf("Error: Input too long.\n");
  } else {
    strcpy(buffer, input);
    printf("Your message: %s\n", buffer);
  }

  return 0;
}
