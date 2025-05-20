#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char shell[1024];

int main() {
  gets(shell);
  printf("%s", shell);
  return 0;
}
