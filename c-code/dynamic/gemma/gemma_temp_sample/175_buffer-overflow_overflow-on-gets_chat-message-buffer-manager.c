#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  gets(buffer);

  if (strlen(buffer) > 10) {
    printf("Error: buffer overflow\n");
  } else {
    printf("Message received: %s\n", buffer);
  }

  return 0;
}
