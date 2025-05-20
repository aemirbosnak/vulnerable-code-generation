#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char cmd[1024];
  printf("Enter a command: ");
  scanf("%s", cmd);
  system(cmd);
  return 0;
}
