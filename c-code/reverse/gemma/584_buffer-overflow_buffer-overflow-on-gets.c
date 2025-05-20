#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char name[10];
  gets(name);
  if (strlen(name) > 10) {
    printf("Error: name too long.\n");
  } else {
    printf("Hello, %s!\n", name);
  }
  return 0;
}
