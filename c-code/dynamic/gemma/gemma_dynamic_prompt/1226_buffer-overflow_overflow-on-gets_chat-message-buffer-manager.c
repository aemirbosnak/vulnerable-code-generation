#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10] = "";
  char message[200] = "This is a message that is too long for the buffer";

  gets(buffer);

  if (strlen(buffer) > 10) {
    printf("Error: Buffer overflow.\n");
  } else {
    printf("Message received: %s\n", buffer);
  }

  return 0;
}
