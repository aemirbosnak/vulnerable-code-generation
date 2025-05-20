#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char buffer[10];
  int i = 0;

  fp = fopen("test.txt", "w");
  if (fp == NULL) {
    return 1;
  }

  while (i < 11) {
    buffer[i] = 'a' + i;
    i++;
  }

  fwrite(buffer, 1, 11, fp);
  fclose(fp);

  return 0;
}
