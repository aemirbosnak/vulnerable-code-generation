#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  scanf("%s", input);
  int light_level = atoi(input);
  if (light_level >= 0 && light_level <= 100) {
    // Set the light level
  } else {
    // Error message
  }
  return 0;
}
