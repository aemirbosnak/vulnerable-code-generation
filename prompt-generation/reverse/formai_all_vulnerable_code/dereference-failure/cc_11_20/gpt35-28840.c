//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char name[20], filename[20], newname[20], data[200];
  FILE *fp, *fp1;
  int option, num, i;

  printf("1. Create a file and write to it.\n");
  printf("2. Read the contents of a file.\n");
  printf("3. Append a file.\n");
  printf("4. Rename a file.\n");
  printf("5. Copy contents of one file to another.\n");
  printf("Enter your option: ");
  scanf("%d", &option);

  switch (option) {

    case 1:
      printf("Enter the filename to create: ");
      scanf("%s", filename);

      fp = fopen(filename, "w");
      if (fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
      }

      printf("Enter the data to write to the file (max 200 characters):\n");
      scanf(" %[^\n]", data);

      fprintf(fp, "%s", data);
      fclose(fp);

      printf("Data written to the file %s successfully.\n", filename);
      break;

    case 2:
      printf("Enter the name of the file to read: ");
      scanf("%s", filename);

      fp = fopen(filename, "r");
      if (fp == NULL) {
        printf("Error reading file.\n");
        exit(1);
      }

      while (fgets(data, 200, fp)) {
        printf("%s", data);
      }

      fclose(fp);
      break;

    case 3:
      printf("Enter the name of the file to append: ");
      scanf("%s", filename);

      fp = fopen(filename, "a");
      if (fp == NULL) {
        printf("Error appending file.\n");
        exit(1);
      }

      printf("Enter the data to append to the file:\n");
      scanf(" %[^\n]", data);

      fprintf(fp, "%s", data);
      fclose(fp);

      printf("Data appended to the file %s successfully.\n", filename);
      break;

    case 4:
      printf("Enter the name of the file to rename: ");
      scanf("%s", name);

      printf("Enter the new name for the file: ");
      scanf("%s", newname);

      if (rename(name, newname) == 0) {
        printf("File renamed successfully.\n");
      } else {
        printf("Error renaming file.\n");
      }
      break;

    case 5:
      printf("Enter the name of the source file: ");
      scanf("%s", name);

      printf("Enter the name of the target file: ");
      scanf("%s", filename);

      fp = fopen(name, "r");
      if (fp == NULL) {
        printf("Error reading file.\n");
        exit(1);
      }

      fp1 = fopen(filename, "w");
      if (fp1 == NULL) {
        printf("Error creating file.\n");
        exit(1);
      }

      while (fgets(data, 200, fp)) {
        fprintf(fp1, "%s", data);
      }

      fclose(fp);
      fclose(fp1);

      printf("Contents copied from %s to %s successfully.\n", name, filename);
      break;

    default:
      printf("Invalid option.\n");
      break;
  }

  return 0;
}