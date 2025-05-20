#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  char **elements = NULL;
  int i = 0;

  fp = fopen("periodic_table.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  getline(&line, &len, fp);
  elements = strdup(line);
  elements = strtok(elements, ",");

  for (i = 0; elements[i] != NULL; i++) {
    printf("What is the chemical symbol for %s?\n", elements[i]);
    char answer[20];
    scanf("%s", answer);

    if (strcmp(answer, elements[i]) == 0) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The answer is %s.\n", elements[i]);
    }
  }

  fclose(fp);
  free(line);
  free(elements);

  return 0;
}
