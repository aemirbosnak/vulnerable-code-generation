#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("periodic_table.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  char line[1024];
  fgets(line, 1024, fp);
  char *elements = strtok(line, ",");

  while (elements) {
    printf("%s ", elements);
    elements = strtok(NULL, ",");
  }

  fclose(fp);
  return 0;
}
