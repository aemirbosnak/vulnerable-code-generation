#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("test.txt", "w");
  char buffer[1024];
  int i = 0;

  while (i < 1024) {
    buffer[i] = 'a';
    i++;
  }

  fwrite(buffer, 1, 1024, fp);
  fclose(fp);

  return 0;
}
