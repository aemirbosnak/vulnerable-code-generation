#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  char input[1024];

  printf("Enter audio stream data: ");
  scanf("%s", input);

  // Overflow on sscanf
  sscanf(input, "%s", buffer);

  // Play audio data
  printf("Audio data: %s\n", buffer);

  return 0;
}
