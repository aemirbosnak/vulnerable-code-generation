#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[1024];
  scanf("%s", input);

  if (strlen(input) > 10) {
    printf("Error: input too long.\n");
  } else {
    printf("You entered: %s\n", input);
  }

  return 0;
}
