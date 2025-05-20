#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char buf[1024];
  gets(buf);

  if (buf[0] == 'a' && buf[1] == 'b' && buf[2] == 'c') {
    if (buf[3] == 'x') {
      printf("You entered the secret sequence.\n");
    } else if (buf[3] == 'y') {
      printf("You entered the wrong sequence.\n");
    }
  } else {
    printf("Invalid input.\n");
  }

  return 0;
}
