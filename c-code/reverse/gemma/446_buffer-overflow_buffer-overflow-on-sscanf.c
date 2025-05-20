#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  scanf("%s", input);
  sscanf(input, "on", 0);
  printf("Lights are on.\n");
  return 0;
}
