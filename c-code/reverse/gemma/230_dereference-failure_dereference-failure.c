#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("periodic_table.txt", "r");
  char line[1024];
  fgets(line, 1024, fp);
  char **elements = (char**)malloc(sizeof(char *) * 100);
  int i = 0;
  while (fgets(line, 1024, fp) != NULL) {
    elements[i++] = strdup(line);
  }
  fclose(fp);

  printf("Enter the element you want to know about: ");
  char element[256];
  scanf("%s", element);

  for (i = 0; elements[i] != NULL; i++) {
    if (strcmp(element, elements[i]) == 0) {
      printf("Element: %s\n", elements[i]);
    }
  }

  return 0;
}
