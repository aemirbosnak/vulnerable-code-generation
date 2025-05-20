#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("text.txt", "r");
  char str[1000];
  fscanf(fp, "%[^\n]", str);
  fclose(fp);

  char *word = strtok(str, " \t\n,.?!:");
  int frequency[50] = {0};
  while (word) {
    word = strtok(NULL, " \t\n,.?!:");
    if (word) {
      frequency[word[0] - 97]++;
    }
  }

  printf("Word frequencies:\n");
  for (int i = 0; i < 50; i++) {
    if (frequency[i] > 0) {
      printf("%c: %d\n", i + 97, frequency[i]);
    }
  }

  return 0;
}
