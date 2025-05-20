#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[10];
  gets(str);

  switch (strlen(str)) {
    case 0:
      printf("Error: input is empty\n");
      break;
    case 1:
      printf("Error: input is too short\n");
      break;
    default:
      printf("Input: %s\n", str);
  }

  return 0;
}
