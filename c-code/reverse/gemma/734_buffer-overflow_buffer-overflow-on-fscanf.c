#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  FILE* pipe = popen("top -b", "r");
  fscanf(pipe, "%s", buffer);
  pclose(pipe);

  int i = 0;
  char** process_list = (char**)malloc(10 * sizeof(char*));
  process_list[0] = buffer;

  for (i = 1; fgets(buffer, 10, pipe) != NULL; i++) {
    process_list[i] = buffer;
  }

  free(process_list);
  return 0;
}
