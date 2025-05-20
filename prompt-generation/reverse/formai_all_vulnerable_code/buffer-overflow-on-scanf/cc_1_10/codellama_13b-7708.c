//Code Llama-13B DATASET v1.0 Category: File handling ; Style: invasive
/*
 * File handling example program in an invasive style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file details
struct File {
  char name[100];
  int size;
  char type[10];
};

int main() {
  struct File file;

  // Get file details
  printf("Enter file name: ");
  scanf("%s", file.name);
  printf("Enter file size: ");
  scanf("%d", &file.size);
  printf("Enter file type: ");
  scanf("%s", file.type);

  // Check if file already exists
  FILE *fp = fopen(file.name, "r");
  if (fp == NULL) {
    // File does not exist, create new file
    fp = fopen(file.name, "w");
    if (fp == NULL) {
      printf("Error creating file\n");
      return 1;
    }
  } else {
    // File already exists, overwrite existing file
    fclose(fp);
    fp = fopen(file.name, "w");
    if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
    }
  }

  // Write file details to file
  fprintf(fp, "File Name: %s\n", file.name);
  fprintf(fp, "File Size: %d\n", file.size);
  fprintf(fp, "File Type: %s\n", file.type);

  // Close file
  fclose(fp);

  return 0;
}