#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  scanf("%s", buffer);

  if (strlen(buffer) > 10) {
    printf("Error: Buffer overflow\n");
  } else {
    printf("Data: %s\n", buffer);
  }

  return 0;
}
