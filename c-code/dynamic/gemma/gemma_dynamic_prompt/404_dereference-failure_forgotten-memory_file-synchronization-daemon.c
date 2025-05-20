#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("test.txt", "w");
  fclose(fp);

  char *ptr = NULL;
  *ptr = 0xdeadbeef;

  printf("%s", ptr);

  return 0;
}
