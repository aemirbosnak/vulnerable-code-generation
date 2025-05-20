#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char line[256];
  int i, r, n, element_num;
  char element_symbol[20];

  fp = fopen("periodic_table.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  n = 0;
  while (fgets(line, 256, fp) != NULL) {
    n++;
  }
  fclose(fp);

  r = rand() % n;
  fp = fopen("periodic_table.txt", "r");
  for (i = 0; i < n; i++) {
    fgets(line, 256, fp);
    element_num = atoi(line);
    if (element_num == r) {
      element_symbol[0] = line[10];
      element_symbol[1] = '\0';
      printf("What is the name of the element with symbol '%c'?", element_symbol[0]);
      scanf("%s", element_symbol);
      if (strcmp(element_symbol, line[10]) != 0) {
        printf("Error: incorrect answer.\n");
      } else {
        printf("Correct! You have successfully answered the question.\n");
      }
    }
  }
  fclose(fp);

  return 0;
}
