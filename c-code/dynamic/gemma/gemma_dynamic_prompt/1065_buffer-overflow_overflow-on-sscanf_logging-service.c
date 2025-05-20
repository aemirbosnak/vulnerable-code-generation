#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char input[20];

  printf("Enter a message: ");
  scanf("%s", input);

  // Buffer overflow
  sprintf(buffer, "Log entry: %s", input);

  // Print the log entry
  printf("%s\n", buffer);

  return 0;
}
