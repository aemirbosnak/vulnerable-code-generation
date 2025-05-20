//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Initialize variables
  char *file1, *file2;
  int size1, size2;

  // Get file names from user
  printf("Enter the name of the first file: ");
  scanf("%s", file1);
  printf("Enter the name of the second file: ");
  scanf("%s", file2);

  // Get file sizes
  FILE *fp1 = fopen(file1, "r");
  FILE *fp2 = fopen(file2, "r");
  fseek(fp1, 0L, SEEK_END);
  size1 = ftell(fp1);
  fseek(fp2, 0L, SEEK_END);
  size2 = ftell(fp2);
  fclose(fp1);
  fclose(fp2);

  // Check if file sizes are equal
  if (size1 != size2) {
    printf("File sizes are not equal.\n");
    return 1;
  }

  // Compare files line by line
  FILE *fp3 = fopen(file1, "r");
  FILE *fp4 = fopen(file2, "r");
  char line1[1024], line2[1024];
  int line_num = 0;
  while (fgets(line1, sizeof(line1), fp3) && fgets(line2, sizeof(line2), fp4)) {
    line_num++;
    if (strcmp(line1, line2) != 0) {
      printf("Files differ at line %d.\n", line_num);
      return 1;
    }
  }
  fclose(fp3);
  fclose(fp4);

  // If no differences found, print success message
  printf("Files are identical.\n");
  return 0;
}