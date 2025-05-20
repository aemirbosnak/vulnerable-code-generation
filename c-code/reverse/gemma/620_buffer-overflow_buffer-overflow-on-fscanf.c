#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  FILE *file;
  char word[10];

  printf("1. Open file\n");
  printf("2. Create file\n");
  printf("3. Exit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      file = fopen("test.txt", "r");
      fscanf(file, "%s", word);
      printf("Word: %s\n", word);
      fclose(file);
      break;
    case 2:
      file = fopen("test.txt", "w");
      fprintf(file, "Hello, world!");
      fclose(file);
      break;
    case 3:
      exit(0);
    default:
      printf("Invalid choice\n");
  }

  return 0;
}
