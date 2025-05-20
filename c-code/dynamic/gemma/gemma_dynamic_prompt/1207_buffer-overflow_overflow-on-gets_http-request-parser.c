#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buf[1024];

int main() {
  gets(buf);
  printf("%s", buf);
  return 0;
}
