#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[1024];

int main() {
  FILE *fp;
  fp = fopen("test.txt", "w");
  printf("Enter text: ");
  scanf("%s", buffer);
  fprintf(fp, "%s", buffer);
  fclose(fp);
  return 0;
}
