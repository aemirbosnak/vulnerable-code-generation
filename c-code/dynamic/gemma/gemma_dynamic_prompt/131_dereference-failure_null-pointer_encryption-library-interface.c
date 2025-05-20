#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str) {
  // Vulnerable code
  *(str - 1) = 'A';
  printf("%s", str);
}

int main() {
  char *str = malloc(10);
  strcpy(str, "Secret message");
  encrypt(str);
  free(str);
  return 0;
}
