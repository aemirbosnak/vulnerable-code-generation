#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[100];
  FILE *fp;
  int i, j, k;
  char data[1000];

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  k = 0;
  while (fgets(data, 1000, fp) != NULL) {
    for (i = 0; data[i] != '\0'; i++) {
      for (j = 0; data[i] != '\n'; j++) {
        if (data[i] < 32 || data[i] > 126) {
          printf("Error: invalid ASCII character.\n");
          fclose(fp);
          exit(1);
        }
      }
    }
    k++;
  }

  fclose(fp);

  printf("Number of lines in file: %d\n", k);

  return 0;
}
