#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("diary.txt", "r");
  char entry[1024];

  fscanf(fp, "%s", entry);
  printf("%s", entry);

  fclose(fp);

  return 0;
}
