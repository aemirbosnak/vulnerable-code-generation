#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char entry[1024];
  FILE *fp = fopen("diary.txt", "r");
  int choice;

  printf("Menu:\n1. Write\n2. Read\n3. Exit\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter your entry: ");
      fgets(entry, 1024, stdin);
      fprintf(fp, "%s\n", entry);
      break;
    case 2:
      fscanf(fp, "%[^\n]%*c", entry);
      printf("Your entry: %s\n", entry);
      break;
    case 3:
      fclose(fp);
      exit(0);
  }

  fclose(fp);
  return 0;
}
