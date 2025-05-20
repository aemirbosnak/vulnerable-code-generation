#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **messages = NULL;
  messages = malloc(10 * sizeof(char *));

  for (int i = 0; i < 10; i++) {
    messages[i] = NULL;
  }

  messages[5] = "Hello, world!";

  printf("%s", messages[5]);

  free(messages);

  return 0;
}
