#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024] = "";
  int len = 0;

  printf("Enter HTTP request: ");
  scanf("%s", buffer);

  len = strlen(buffer);

  if (len > 1024) {
    printf("Error: Buffer overflow.\n");
  } else {
    printf("Request: %s\n", buffer);
  }

  return 0;
}
