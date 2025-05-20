#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i = 0;
  FILE *fp = fopen("/tmp/foo.log", "w");
  for (i = 0; i < 100000; i++) {
    fprintf(fp, "%s\n", "This is a message");
  }
  fclose(fp);
  return 0;
}
