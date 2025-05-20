#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("/proc/meminfo", "r");
  char line[1024];
  while (fgets(line, 1024, fp) != NULL) {
    char value[64];
    sscanf(line, "Swap: %s", value);
    long int swap_space = atoi(value);
    printf("Swap space: %ld KB\n", swap_space);
  }
  fclose(fp);
  return 0;
}
