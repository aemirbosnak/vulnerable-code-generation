#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  printf("Enter C code: ");
  fgets(str, 1000, stdin);

  char *ptr = str;
  while (*ptr) {
    // Datatype identification
    if (*ptr >= 'a' && *ptr <= 'z') {
      printf("Datatype: %c\n", *ptr);
    }

    // Loop structure identification
    if (*ptr == '{' || *ptr == '}' || *ptr == 'for' || *ptr == 'while' || *ptr == 'do') {
      printf("Loop structure: %c\n", *ptr);
    }

    ptr++;
  }

  return 0;
}
