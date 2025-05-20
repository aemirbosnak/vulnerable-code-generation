#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("periodic_table.txt", "r");
  char *line = NULL;
  size_t len = 0;
  int i = 0;
  char **elements = NULL;

  if (fp) {
    while (getline(&line, &len, fp) != -1) {
      elements = realloc(elements, (i + 1) * sizeof(char *));
      elements[i++] = strdup(line);
    }
  }

  fclose(fp);

  for (i = 0; elements[i] != NULL; i++) {
    printf("%s\n", elements[i]);
  }

  free(elements);
  return 0;
}
