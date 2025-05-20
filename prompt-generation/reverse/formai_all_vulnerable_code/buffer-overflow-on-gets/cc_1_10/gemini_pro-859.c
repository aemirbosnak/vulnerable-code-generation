//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  FILE *src, *dest;
  char ch;
  char src_file[255];
  char dest_file[255];

  // Get the source and destination filenames
  printf("Enter the source filename: ");
  gets(src_file);
  printf("Enter the destination filename: ");
  gets(dest_file);
  
  // Open the source file in read mode
  src = fopen(src_file, "r");

  // Check if the source file was opened successfully
  if (src == NULL) {
    printf("Error opening source file '%s'\n", src_file);
    exit(1);
  }

  // Open the destination file in write mode
  dest = fopen(dest_file, "w");

  // Check if the destination file was opened successfully
  if (dest == NULL) {
    printf("Error opening destination file '%s'\n", dest_file);
    exit(1);
  }

  // Copy the contents of the source file to the destination file
  while ((ch = fgetc(src)) != EOF) {
    fputc(ch, dest);
  }

  // Close the source file
  fclose(src);

  // Close the destination file
  fclose(dest);

  // Success!
  printf("File '%s' backed up successfully to '%s'!\n", src_file, dest_file);

  return 0;
}