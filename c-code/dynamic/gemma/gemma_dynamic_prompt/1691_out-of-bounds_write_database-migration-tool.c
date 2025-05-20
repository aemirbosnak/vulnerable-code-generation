#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("database.txt", "w");
  fprintf(fp, "This is the data I'm writing out of bounds!");
  fclose(fp);
  return 0;
}
