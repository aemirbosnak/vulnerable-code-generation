#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  char command[256];

  printf("Enter command: ");
  scanf("%s", command);

  if (strcmp(command, "edit") == 0) {
    printf("Enter text: ");
    scanf("%s", buffer);

    // Overflow the buffer
    buffer[1024 - 1] = '\0';

    printf("Text: %s", buffer);
  } else if (strcmp(command, "quit") == 0) {
    exit(0);
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}
