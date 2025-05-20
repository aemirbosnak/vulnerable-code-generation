#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **messages = NULL;
  int size = 0;

  // Allocate memory for the first message
  messages = malloc(sizeof(char *) * 1);
  messages[0] = malloc(10);

  // Write the first message
  messages[0][0] = 'H';
  messages[0][1] = 'i';
  messages[0][2] = 'r';
  messages[0][3] = 'o';
  messages[0][4] = '\0';

  // Free the memory for the first message
  free(messages[0]);
  free(messages);

  return 0;
}
