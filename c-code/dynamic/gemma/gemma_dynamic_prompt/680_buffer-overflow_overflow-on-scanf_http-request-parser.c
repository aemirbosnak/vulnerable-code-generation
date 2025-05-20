#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[100];
  scanf("%s", buffer);

  if (strlen(buffer) > 100) {
    printf("Error: buffer overflow\n");
  } else {
    printf("Your input: %s\n", buffer);
  }

  return 0;
}
