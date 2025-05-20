#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char* ptr = NULL;
  *ptr = 'a';
  printf("%c", *ptr);
  return 0;
}
