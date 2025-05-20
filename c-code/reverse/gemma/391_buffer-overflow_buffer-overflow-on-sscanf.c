#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1024];
  scanf("%s", input);

  char *port_range = strtok(input, "-");
  int start_port = atoi(port_range);
  int end_port = atoi(strtok(NULL, "-")) - 1;

  for (int i = start_port; i <= end_port; i++) {
    // Scan port i
  }

  return 0;
}
