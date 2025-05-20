#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("diary.txt", "r");
  if (fp == NULL) {
    fp = fopen("diary.txt", "w");
  }

  char entry[1024];
  printf("Enter your entry: ");
  scanf("%s", entry);

  fprintf(fp, "%s\n", entry);
  fclose(fp);

  return 0;
}
