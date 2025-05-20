#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[256];
  int choice;

  printf("Enter file name: ");
  fscanf(stdin, "%s", filename);

  printf("Select an option:\n");
  printf("1. Read file\n");
  printf("2. Write file\n");
  printf("3. Delete file\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      FILE *file = fopen(filename, "r");
      if (file) {
        char buffer[1024];
        fscanf(file, "%s", buffer);
        printf("File content: %s", buffer);
        fclose(file);
      } else {
        printf("Error opening file");
      }
      break;
    case 2:
      file = fopen(filename, "w");
      if (file) {
        char data[1024];
        printf("Enter file content: ");
        fscanf(stdin, "%s", data);
        fprintf(file, "%s", data);
        fclose(file);
      } else {
        printf("Error opening file");
      }
      break;
    case 3:
      file = fopen(filename, "r");
      if (file) {
        fclose(file);
        remove(filename);
        printf("File deleted");
      } else {
        printf("Error deleting file");
      }
      break;
    default:
      printf("Invalid option");
  }

  return 0;
}
