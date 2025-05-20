#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char buffer[10];
  FILE* file = fopen("diary.txt", "r");
  fscanf(file, "%s", buffer);
  fclose(file);
  return 0;
}
