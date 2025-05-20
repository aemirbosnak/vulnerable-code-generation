#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

  char **logs = NULL;
  logs = malloc(10 * sizeof(char *));
  logs[0] = "This is a log message";
  logs[1] = NULL;

  printf("%s", logs[0]);
  free(logs);

  return 0;
}
