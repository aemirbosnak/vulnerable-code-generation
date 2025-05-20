#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter C code: ");
  scanf("%s", str);

  char *ptr = str;
  while (*ptr) {
    if (strchr("int float char for while switch", *ptr) != NULL) {
      printf("Keyword found: %c\n", *ptr);
    } else {
      printf("Character: %c\n", *ptr);
    }
    ptr++;
  }

  return 0;
}
