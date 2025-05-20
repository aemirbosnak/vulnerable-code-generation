#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/proc/meminfo", "r");
  char line[4096];
  int i = 0;

  if (fp) {
    while (fgets(line, sizeof(line), fp) != NULL) {
      char mem_type[20];
      int pages, free, used, shared;

      sscanf(line, " %s %d %d %d ", mem_type, &pages, &free, &used, &shared);

      i++;
    }

    fclose(fp);
  }

  printf("Number of lines in /proc/meminfo: %d\n", i);

  return 0;
}
