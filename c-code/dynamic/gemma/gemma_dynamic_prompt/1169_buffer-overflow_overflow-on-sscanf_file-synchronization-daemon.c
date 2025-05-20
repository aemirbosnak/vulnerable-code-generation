#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10] = "";
  char input[1024] = "";

  printf("Enter a file path: ");
  scanf("%s", input);

  // Overflow on sscanf
  scanf("%s", buffer);

  // Do something with the file path and data
  printf("File path: %s, Data: %s", input, buffer);

  return 0;
}
