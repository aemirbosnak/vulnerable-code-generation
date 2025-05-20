#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char code[1024];
  gets(code);

  // Parse the code and identify datatypes and loop structures
  char *ptr = code;
  while (*ptr) {
    // Datatype identification
    if (*ptr >= 'a' && *ptr <= 'z') {
      printf("Datatype: %c\n", *ptr);
    }

    // Loop structure identification
    if (*ptr == '{' || *ptr == '}' || *ptr == 'for' || *ptr == 'while') {
      printf("Loop structure: %c\n", *ptr);
    }

    ptr++;
  }

  return 0;
}
