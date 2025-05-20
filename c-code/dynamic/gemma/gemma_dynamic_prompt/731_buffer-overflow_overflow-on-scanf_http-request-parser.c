#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buf[1024];
  scanf("%s", buf);

  // This line will overflow the buffer, but the program will not crash
  buf[1024 - 1] = 'a';

  printf("The buffer content is: %s", buf);

  return 0;
}
