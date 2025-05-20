#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char buffer[10];
  char input[1024];

  printf("Enter a message: ");
  scanf("%s", input);

  // Overflow the buffer by writing more than the allocated size
  sprintf(buffer, "Log Entry: %s", input);

  // Print the log entry
  printf("%s\n", buffer);

  return 0;
}
