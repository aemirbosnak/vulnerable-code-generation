#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  FILE *fp = fopen("/tmp/foo.txt", "w");
  fprintf(fp, "Hello, world!");
  fclose(fp);

  system("/bin/cp /tmp/foo.txt ./");

  return 0;
}
