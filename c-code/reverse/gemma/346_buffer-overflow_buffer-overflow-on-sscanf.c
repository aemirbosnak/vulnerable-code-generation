#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char query[1024];
  scanf("%s", query);

  char record[1024];
  FILE *fp = fopen("records.txt", "r");
  while (fgets(record, 1024, fp) != NULL) {
    char name[256];
    int age;
    sscanf(record, "Name: %s, Age: %d", name, &age);

    if (strcmp(name, query) == 0) {
      printf("Record found: Name: %s, Age: %d\n", name, age);
    }
  }

  fclose(fp);
  return 0;
}
