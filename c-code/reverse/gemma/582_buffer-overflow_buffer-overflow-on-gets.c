#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char name[10];
  gets(name);
  printf("Hello, %s!", name);

  char move[20];
  gets(move);
  printf("Your move: %s", move);

  return 0;
}
