#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char input[1024];

  printf("Enter audio stream data: ");
  scanf("%s", input);

  // Overflow on sscanf
  sscanf(input, "%[^\n]%c", buffer, NULL);

  // Play audio stream
  printf("Playing audio stream...\n");
  printf("%s\n", buffer);

  return 0;
}
