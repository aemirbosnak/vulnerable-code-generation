#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void plugin_loader(char **buffer) {
  char command[1024];
  fscanf(stdin, "%s", command);

  *buffer = malloc(strlen(command) + 1);
  strcpy(*buffer, command);
}

int main() {
  char *buffer;
  plugin_loader(&buffer);
  printf("%s", buffer);
  free(buffer);
  return 0;
}
