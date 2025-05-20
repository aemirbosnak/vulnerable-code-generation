#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;
  FILE *file;

  printf("1. Create file\n");
  printf("2. Read file\n");
  printf("3. Write file\n");
  printf("4. Word count\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      file = fopen("my_file.txt", "w");
      fclose(file);
      break;
    case 2:
      file = fopen("my_file.txt", "r");
      fscanf(file, "%s", "");
      fclose(file);
      break;
    case 3:
      file = fopen("my_file.txt", "w");
      printf("Enter text: ");
      fscanf(file, "%s", "");
      fclose(file);
      break;
    case 4:
      file = fopen("my_file.txt", "r");
      fscanf(file, "%s", "");
      fclose(file);
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}
