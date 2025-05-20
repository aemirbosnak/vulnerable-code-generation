#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char code[1024];
  gets(code);

  char *ptr = code;
  while (*ptr) {
    if (*ptr == 'i' || *ptr == 'f' || *ptr == 'c') {
      printf("Datatype: %c\n", *ptr);
    } else if (*ptr == 'f' || *ptr == 'w' || *ptr == 's') {
      printf("Loop structure: %c\n", *ptr);
    } else if (*ptr != '\0') {
      printf("Leftover character: %c\n", *ptr);
    }
    ptr++;
  }

  return 0;
}
