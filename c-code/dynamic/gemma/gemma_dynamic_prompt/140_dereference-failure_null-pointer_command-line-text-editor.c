#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = NULL;
  char **ptr = &str;

  printf("Enter text: ");
  getline(ptr, 1024, stdin);

  if (*ptr) {
    printf("Your text: %s\n", *ptr);
  } else {
    printf("Error: Null pointer dereference.\n");
  }

  return 0;
}
