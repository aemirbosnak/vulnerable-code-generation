#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = malloc(1024);
  int size = 0;

  printf("Enter text: ");

  // Overflow the buffer
  while (1) {
    char ch = getchar();
    if (ch == '\n') break;
    buf[size++] = ch;
  }

  printf("Your text: %s", buf);

  free(buf);
  return 0;
}
