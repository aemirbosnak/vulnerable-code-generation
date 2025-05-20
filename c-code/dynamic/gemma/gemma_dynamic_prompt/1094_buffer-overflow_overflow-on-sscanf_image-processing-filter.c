#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char input[1024];

  printf("Enter filter parameters: ");
  scanf("%s", input);

  // Buffer overflow on sscanf
  sscanf(input, "%s", buffer);

  // Processing of the filter parameters
  // ...

  printf("Filter parameters: %s", buffer);

  return 0;
}
