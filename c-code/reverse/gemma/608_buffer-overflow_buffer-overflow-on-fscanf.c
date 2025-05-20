#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char entry[100];
  FILE *fp = fopen("diary.txt", "a");
  while (1) {
    printf("Enter entry: ");
    fscanf(stdin, "%s", entry);
    fprintf(fp, "%s\n", entry);
    if (strcmp(entry, "quit") == 0) {
      break;
    }
  }
  fclose(fp);
  return 0;
}
