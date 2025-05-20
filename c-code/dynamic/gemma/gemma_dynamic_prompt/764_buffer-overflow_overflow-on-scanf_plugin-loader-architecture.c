#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *plugin_loader(char **buffer) {
  char *overflow_buffer = malloc(10);
  scanf("%s", overflow_buffer);
  return NULL;
}

int main() {
  char *buffer = NULL;
  plugin_loader(&buffer);
  return 0;
}
